#include "circular_queue_thread_safe.hpp"

template <typename T>
CircularQueue<T>::CircularQueue(size_t capacity)
    : elements_(capacity, std::nullopt),
      capacity_(capacity),
      push_cursor_(0),
      pop_cursor_(0),
      elements_popped_(0),
      elements_pushed_(0),
      is_closed_(false) {}

template <typename T>
bool CircularQueue<T>::Push(const T &element) {
  std::unique_lock<std::mutex> lock(mut_);

  if (is_closed_) {
    return false;
  }

  while (is_full()) {
    cond_.wait(lock);
  }

  elements_[push_cursor_] = std::move(element);
  push_cursor_ = (push_cursor_ + 1) % capacity_;
  elements_pushed_++;
  lock.unlock();
  cond_.notify_one();

  return true;
}

template <typename T>
bool CircularQueue<T>::Pop() {
  std::unique_lock<std::mutex> lock(mut_);

  while (is_empty()) {
    if (is_finished()) {
      return false;
    }
    cond_.wait(lock);
  }

  elements_[pop_cursor_] = std::nullopt;
  pop_cursor_ = (pop_cursor_ + 1) % capacity_;
  elements_popped_++;
  lock.unlock();
  cond_.notify_all();

  return true;
}

template <typename T>
const T &CircularQueue<T>::Front() {
  std::unique_lock<std::mutex> lock(mut_);
  return front();
}

template <typename T>
const T &CircularQueue<T>::front() {
  std::unique_lock<std::mutex> lock(mut_);

  if (is_empty()) {
    throw std::runtime_error("No elements in queue");
  }

  return elements_[pop_cursor_].value();
}

template <typename T>
size_t CircularQueue<T>::Size() {
  std::unique_lock<std::mutex> lock(mut_);
  return size();
}

template <typename T>
size_t CircularQueue<T>::size() {
  if (is_full()) {
    return capacity_;
  }

  if (pop_cursor_ <= push_cursor_) {
    return static_cast<size_t>(push_cursor_ - pop_cursor_);
  }

  return static_cast<size_t>(push_cursor_ + (capacity_ - pop_cursor_));
}

template <typename T>
bool CircularQueue<T>::IsEmpty() {
  std::unique_lock<std::mutex> lock(mut_);
  return is_empty();
}

template <typename T>
bool CircularQueue<T>::is_empty() {
  return !elements_[pop_cursor_].has_value();
}

template <typename T>
bool CircularQueue<T>::IsFull() {
  std::unique_lock<std::mutex> lock(mut_);
  return is_full();
}

template <typename T>
bool CircularQueue<T>::is_full() {
  return push_cursor_ == pop_cursor_ && elements_[pop_cursor_].has_value();
}

template <typename T>
void CircularQueue<T>::Close() {
  std::unique_lock<std::mutex> lock(mut_);
  close();
  lock.unlock();
  cond_.notify_all();
}

template <typename T>
void CircularQueue<T>::close() {
  is_closed_ = true;
}

template <typename T>
bool CircularQueue<T>::IsFinished() {
  std::unique_lock<std::mutex> lock(mut_);
  return is_finished();
}

template <typename T>
bool CircularQueue<T>::is_finished() {
  return is_closed_ && is_empty();
}

template <typename T>
void CircularQueue<T>::Print() {
  std::unique_lock<std::mutex> lock(mut_);

  std::cout << "[ ";

  if (!is_empty()) {
    auto index = pop_cursor_;

    do {
      std::cout << elements_[index].value() << " ";
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
