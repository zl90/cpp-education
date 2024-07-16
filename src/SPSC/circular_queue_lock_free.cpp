#include "circular_queue_lock_free.hpp"

template <typename T>
CircularQueueLockFree<T>::CircularQueueLockFree(size_t capacity)
    : elements_{std::allocator_traits<std::allocator<T>>::allocate(allocator_,
                                                                   capacity)},
      capacity_(capacity), push_cursor_(0), pop_cursor_(0), elements_popped_(0),
      elements_pushed_(0), is_closed_(false) {}

template <typename T> CircularQueueLockFree<T>::~CircularQueueLockFree() {
  while (!is_empty()) {
    elements_[pop_cursor_ % capacity_].~T();
    pop_cursor_++;
  }
  std::allocator_traits<std::allocator<T>>::deallocate(allocator_, elements_,
                                                       capacity_);
}

template <typename T> bool CircularQueueLockFree<T>::Push(const T &element) {
  if (is_closed_) {
    return false;
  }

  while (is_full()) {
  }

  new (&elements_[push_cursor_ % capacity_])
      T(element); // Allocate using placement new
  push_cursor_++;
  elements_pushed_++;

  return true;
}

template <typename T> bool CircularQueueLockFree<T>::Pop() {
  while (is_empty()) {
    if (is_finished()) {
      return false;
    }
  }

  elements_[pop_cursor_ % capacity_].~T(); // Deallocate using placement new
  pop_cursor_++;
  elements_popped_++;

  return true;
}

template <typename T> const T &CircularQueueLockFree<T>::Front() {
  return front();
}

template <typename T> const T &CircularQueueLockFree<T>::front() {
  if (is_empty()) {
    throw std::runtime_error("No elements in queue");
  }

  return elements_[pop_cursor_ % capacity_];
}

template <typename T> size_t CircularQueueLockFree<T>::Size() { return size(); }

template <typename T> size_t CircularQueueLockFree<T>::size() {
  return static_cast<size_t>(push_cursor_ - pop_cursor_);
}

template <typename T> bool CircularQueueLockFree<T>::IsEmpty() {
  return is_empty();
}

template <typename T> bool CircularQueueLockFree<T>::is_empty() {
  return size() == 0;
}

template <typename T> bool CircularQueueLockFree<T>::IsFull() {
  return is_full();
}

template <typename T> bool CircularQueueLockFree<T>::is_full() {
  return size() == capacity_;
}

template <typename T> void CircularQueueLockFree<T>::Close() { close(); }

template <typename T> void CircularQueueLockFree<T>::close() {
  is_closed_ = true;
}

template <typename T> bool CircularQueueLockFree<T>::IsFinished() {
  return is_finished();
}

template <typename T> bool CircularQueueLockFree<T>::is_finished() {
  return is_closed_ && is_empty();
}

template <typename T> void CircularQueueLockFree<T>::Print() {

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
