#include "circular_queue_thread_safe.hpp"

template <typename T>
CircularQueue<T>::CircularQueue(size_t capacity)
    : elements_(capacity, std::nullopt),
      capacity_(capacity),
      push_cursor_(0),
      pop_cursor_(0) {}

template <typename T>
bool CircularQueue<T>::Push(const T &element) {
  std::unique_lock<std::mutex> lock(mut_);

  while (Full()) {
    cond_.wait(lock);
  }

  elements_[push_cursor_] = std::move(element);
  push_cursor_ = (push_cursor_ + 1) % capacity_;
  lock.unlock();
  cond_.notify_all();

  return true;
}

template <typename T>
bool CircularQueue<T>::Pop() {
  std::unique_lock<std::mutex> lock(mut_);

  while (Empty()) {
    cond_.wait(lock);
  }

  elements_[pop_cursor_] = std::nullopt;
  pop_cursor_ = (pop_cursor_ + 1) % capacity_;
  lock.unlock();
  cond_.notify_all();
  return true;
}

template <typename T>
const T &CircularQueue<T>::Front() {
  std::unique_lock<std::mutex> lock(mut_);

  if (!elements_[pop_cursor_].has_value()) {
    throw std::runtime_error("No elements in queue");
  }

  return elements_[pop_cursor_].value();
}

template <typename T>
size_t CircularQueue<T>::Size() {
  std::unique_lock<std::mutex> lock(mut_);

  if (Full()) {
    return capacity_;
  }

  if (pop_cursor_ <= push_cursor_) {
    return static_cast<size_t>(push_cursor_ - pop_cursor_);
  }

  return static_cast<size_t>(push_cursor_ + (capacity_ - pop_cursor_));
}

template <typename T>
bool CircularQueue<T>::Empty() {
  return !elements_[pop_cursor_].has_value();
}

template <typename T>
bool CircularQueue<T>::Full() {
  return push_cursor_ == pop_cursor_ && elements_[pop_cursor_].has_value();
}

template <typename T>
void CircularQueue<T>::Print() {  // Not thread safe
  std::cout << "[ ";

  if (!Empty()) {
    auto index = pop_cursor_;

    do {
      std::cout << elements_[index].value() << " ";
      index = (index + 1) % capacity_;
    } while (index != push_cursor_);
  }

  std::cout << "] Size: " << Size() << ", Empty: " << Empty()
            << ", Full: " << Full();
  if (Empty()) {
    std::cout << "\n";
  } else {
    std::cout << ", Front: " << Front() << "\n";
  }
}

int main() {
  CircularQueue<int> q(8);

  auto push_thread = [&]() {
    q.Push(1);
    q.Push(1);
    q.Push(1);
    q.Push(1);
    q.Push(1);
    q.Push(1);
    q.Push(1);
    q.Push(1);
    q.Push(1);
    q.Push(1);
  };

  auto pop_thread = [&]() {
    q.Pop();
    // q.Pop();
  };

  std::thread t1(push_thread);
  std::thread t2(pop_thread);
  t1.join();
  t2.join();

  q.Print();
}