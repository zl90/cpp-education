#pragma once

#include <iostream>
#include <optional>
#include <type_traits>
#include <vector>

template <typename T> class CircularQueue {
public:
  CircularQueue<T>(size_t capacity);

  bool Push(const T &element);
  bool Pop();
  const T &Front();
  size_t Size();
  bool Empty();
  bool Full();
  void Print();

private:
  std::vector<std::optional<T>> elements_;
  size_t capacity_;
  int push_cursor_;
  int pop_cursor_;
};
