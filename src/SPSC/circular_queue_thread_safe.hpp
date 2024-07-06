#pragma once

#include <time.h>

#include <chrono>
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
  bool IsEmpty();
  bool IsFull();
  bool IsFinished();
  void Close();
  void Print();

 private:
  std::vector<std::optional<T>> elements_;
  size_t capacity_;
  int push_cursor_;
  int pop_cursor_;
  long long elements_popped_;
  long long elements_pushed_;
  bool is_closed_;

  const T &front();
  size_t size();
  bool is_empty();
  bool is_full();
  bool is_finished();
  void close();

  std::mutex mut_;
  std::condition_variable cond_;
};
