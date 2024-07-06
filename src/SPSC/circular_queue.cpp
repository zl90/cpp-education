#include "circular_queue.hpp"

template <typename T>
CircularQueue<T>::CircularQueue(size_t capacity)
    : elements_(capacity, std::nullopt), capacity_(capacity), push_cursor_(0),
      pop_cursor_(0) {}

template <typename T> bool CircularQueue<T>::Push(const T &element) {
  if (Full()) {
    return false;
  }

  elements_[push_cursor_] = std::move(element);
  push_cursor_ = (push_cursor_ + 1) % capacity_;
  return true;
}

template <typename T> bool CircularQueue<T>::Pop() {
  if (Empty()) {
    return false;
  }

  elements_[pop_cursor_] = std::nullopt;
  pop_cursor_ = (pop_cursor_ + 1) % capacity_;
  return true;
}

template <typename T> const T &CircularQueue<T>::Front() {
  if (!elements_[pop_cursor_].has_value()) {
    throw std::runtime_error("No elements in queue");
  }

  return elements_[pop_cursor_].value();
}

template <typename T> size_t CircularQueue<T>::Size() {
  if (Full()) {
    return capacity_;
  }

  if (pop_cursor_ <= push_cursor_) {
    return static_cast<size_t>(push_cursor_ - pop_cursor_);
  }

  return static_cast<size_t>(push_cursor_ + (capacity_ - pop_cursor_));
}

template <typename T> bool CircularQueue<T>::Empty() {
  return !elements_[pop_cursor_].has_value();
}

template <typename T> bool CircularQueue<T>::Full() {
  return push_cursor_ == pop_cursor_ && elements_[pop_cursor_].has_value();
}

template <typename T> void CircularQueue<T>::Print() {
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

  q.Print();

  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.Push(4);

  q.Print();

  q.Push(5);
  q.Push(6);
  q.Push(7);
  q.Push(8);

  q.Print();

  q.Push(9);

  q.Print();

  q.Pop();
  q.Pop();

  q.Print();

  q.Push(0);
  q.Push(0);
  q.Push(0);

  q.Print();

  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();

  q.Print();

  q.Push(7);
  q.Push(7);
  q.Push(7);

  q.Print();
}