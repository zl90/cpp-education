#pragma once

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <optional>
#include <thread>
#include <type_traits>
#include <vector>

template <typename T>
class CircularQueue {
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

  std::mutex mut_;
  std::condition_variable cond_;
};
