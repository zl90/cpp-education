#include "circular_queue_lock_free_acq_rel_alignas.hpp"

template <typename T>
CircularQueueLockFreeAcqRelAlignas<T>::CircularQueueLockFreeAcqRelAlignas(
    size_t capacity)
    : elements_{std::allocator_traits<std::allocator<T>>::allocate(allocator_,
                                                                   capacity)},
      capacity_(capacity), push_cursor_(0), pop_cursor_(0), elements_popped_(0),
      elements_pushed_(0), is_closed_(false) {}

template <typename T>
CircularQueueLockFreeAcqRelAlignas<T>::~CircularQueueLockFreeAcqRelAlignas() {
  while (!is_empty()) {
    elements_[pop_cursor_ % capacity_].~T();
    pop_cursor_++;
  }
  std::allocator_traits<std::allocator<T>>::deallocate(allocator_, elements_,
                                                       capacity_);
}

template <typename T>
bool CircularQueueLockFreeAcqRelAlignas<T>::Push(const T &element) {
  auto push_cursor = push_cursor_.load(std::memory_order_acquire);

  if (is_closed_.load(std::memory_order_acquire)) {
    return false;
  }

  while (is_full()) {
  }

  new (&elements_[push_cursor % capacity_])
      T(element); // Allocate using placement new
  push_cursor_.store(push_cursor + 1, std::memory_order_release);
  elements_pushed_.fetch_add(1, std::memory_order_acq_rel);

  return true;
}

template <typename T> bool CircularQueueLockFreeAcqRelAlignas<T>::Pop() {
  auto pop_cursor = pop_cursor_.load(std::memory_order_acquire);

  while (is_empty()) {
    if (is_finished()) {
      return false;
    }
  }

  elements_[pop_cursor % capacity_].~T(); // Deallocate using placement new
  pop_cursor_.store(pop_cursor + 1, std::memory_order_release);
  elements_popped_.fetch_add(1, std::memory_order_acq_rel);

  return true;
}

template <typename T> const T &CircularQueueLockFreeAcqRelAlignas<T>::Front() {
  return front();
}

template <typename T> const T &CircularQueueLockFreeAcqRelAlignas<T>::front() {
  auto pop_cursor = pop_cursor_.load(std::memory_order_acquire);

  if (is_empty()) {
    throw std::runtime_error("No elements in queue");
  }

  return elements_[pop_cursor % capacity_];
}

template <typename T> size_t CircularQueueLockFreeAcqRelAlignas<T>::Size() {
  return size();
}

template <typename T> size_t CircularQueueLockFreeAcqRelAlignas<T>::size() {
  auto pop_cursor = pop_cursor_.load(std::memory_order_acquire);
  auto push_cursor = push_cursor_.load(std::memory_order_acquire);

  return static_cast<size_t>(push_cursor - pop_cursor);
}

template <typename T> bool CircularQueueLockFreeAcqRelAlignas<T>::IsEmpty() {
  return is_empty();
}

template <typename T> bool CircularQueueLockFreeAcqRelAlignas<T>::is_empty() {
  return size() == 0;
}

template <typename T> bool CircularQueueLockFreeAcqRelAlignas<T>::IsFull() {
  return is_full();
}

template <typename T> bool CircularQueueLockFreeAcqRelAlignas<T>::is_full() {
  return size() == capacity_;
}

template <typename T> void CircularQueueLockFreeAcqRelAlignas<T>::Close() {
  close();
}

template <typename T> void CircularQueueLockFreeAcqRelAlignas<T>::close() {
  is_closed_.store(true, std::memory_order_release);
}

template <typename T> bool CircularQueueLockFreeAcqRelAlignas<T>::IsFinished() {
  return is_finished();
}

template <typename T>
bool CircularQueueLockFreeAcqRelAlignas<T>::is_finished() {
  auto is_closed = is_closed_.load(std::memory_order_acquire);

  return is_closed_ && is_empty();
}

template <typename T> void CircularQueueLockFreeAcqRelAlignas<T>::Print() {

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
