#include "circular_queue_thread_safe_prealloc.hpp"

template <typename T>
CircularQueuePreAlloc<T>::CircularQueuePreAlloc(size_t capacity)
    : elements_{std::allocator_traits<std::allocator<T>>::allocate(allocator_,
                                                                   capacity)},
      capacity_(capacity), push_cursor_(0), pop_cursor_(0), elements_popped_(0),
      elements_pushed_(0), is_closed_(false) {}

template <typename T> CircularQueuePreAlloc<T>::~CircularQueuePreAlloc() {
  while (!is_empty()) {
    elements_[pop_cursor_ % capacity_].~T();
    pop_cursor_++;
  }
  std::allocator_traits<std::allocator<T>>::deallocate(allocator_, elements_,
                                                       capacity_);
}

template <typename T> bool CircularQueuePreAlloc<T>::Push(const T &element) {
  std::unique_lock<std::mutex> lock(mut_);

  if (is_closed_) {
    return false;
  }

  while (is_full()) {
    cond_.wait(lock);
  }

  new (&elements_[push_cursor_ % capacity_])
      T(element); // Allocate using placement new
  push_cursor_++;
  elements_pushed_++;
  lock.unlock();
  cond_.notify_one();

  return true;
}

template <typename T> bool CircularQueuePreAlloc<T>::Pop() {
  std::unique_lock<std::mutex> lock(mut_);

  while (is_empty()) {
    if (is_finished()) {
      return false;
    }
    cond_.wait(lock);
  }

  elements_[pop_cursor_ % capacity_].~T(); // Deallocate using placement new
  pop_cursor_++;
  elements_popped_++;
  lock.unlock();
  cond_.notify_all();

  return true;
}

template <typename T> const T &CircularQueuePreAlloc<T>::Front() {
  std::unique_lock<std::mutex> lock(mut_);
  return front();
}

template <typename T> const T &CircularQueuePreAlloc<T>::front() {
  std::unique_lock<std::mutex> lock(mut_);

  if (is_empty()) {
    throw std::runtime_error("No elements in queue");
  }

  return elements_[pop_cursor_ % capacity_];
}

template <typename T> size_t CircularQueuePreAlloc<T>::Size() {
  std::unique_lock<std::mutex> lock(mut_);
  return size();
}

template <typename T> size_t CircularQueuePreAlloc<T>::size() {
  return static_cast<size_t>(push_cursor_ - pop_cursor_);
}

template <typename T> bool CircularQueuePreAlloc<T>::IsEmpty() {
  std::unique_lock<std::mutex> lock(mut_);
  return is_empty();
}

template <typename T> bool CircularQueuePreAlloc<T>::is_empty() {
  return size() == 0;
}

template <typename T> bool CircularQueuePreAlloc<T>::IsFull() {
  std::unique_lock<std::mutex> lock(mut_);
  return is_full();
}

template <typename T> bool CircularQueuePreAlloc<T>::is_full() {
  return size() == capacity_;
}

template <typename T> void CircularQueuePreAlloc<T>::Close() {
  std::unique_lock<std::mutex> lock(mut_);
  close();
  lock.unlock();
  cond_.notify_all();
}

template <typename T> void CircularQueuePreAlloc<T>::close() {
  is_closed_ = true;
}

template <typename T> bool CircularQueuePreAlloc<T>::IsFinished() {
  std::unique_lock<std::mutex> lock(mut_);
  return is_finished();
}

template <typename T> bool CircularQueuePreAlloc<T>::is_finished() {
  return is_closed_ && is_empty();
}

template <typename T> void CircularQueuePreAlloc<T>::Print() {
  std::unique_lock<std::mutex> lock(mut_);

  std::cout << "[ ";

  if (!is_empty()) {
    auto index = pop_cursor_ % capacity_;

    do {
      std::cout << elements_[index] << " ";
      index = (index + 1) % capacity_;
    } while (index != push_cursor_);
  }

  std::cout << "] Size: " << size() << ", Empty: " << is_empty()
            << ", Full: " << is_full();
  if (is_empty()) {
    std::cout << "\n";
  } else {
    std::cout << ", Front: " << front() << "\n";
  }

  std::cout << "Elements pushed: " << elements_pushed_
            << ", Elements popped: " << elements_popped_ << "\n";
}
