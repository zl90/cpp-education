#pragma once

#include <time.h>

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <new>
#include <optional>
#include <thread>
#include <type_traits>

/**
 * @brief A thread-safe single producer single consumer FIFO queue implemented
 * using a circular buffer.
 *
 * This queue supports concurrent access from one producer thread and one
 * consumer thread.
 *
 * All memory allocation is done during initialisation. A preallocated buffer is
 * re-used to store elements at runtime.
 */
template <typename T> class CircularQueueLockFreeAcqRel {
public:
  /**
   * @brief Constructs a circular queue with the specified capacity.
   *
   * @param capacity The maximum number of elements the queue can hold.
   */
  CircularQueueLockFreeAcqRel(size_t capacity);

  ~CircularQueueLockFreeAcqRel();

  /**
   * @brief Pushes an element into the queue.
   *
   * If the queue is full, the queue will wait for an element to be popped.
   *
   * @param element The element to push into the queue.
   * @return true if the element was successfully pushed; false if the queue is
   * finished.
   */
  bool Push(const T &element);

  /**
   * @brief Pops an element from the front of the queue.
   *
   * Waits until an element is available if the queue is empty.
   *
   * @return true if an element was successfully popped; false if the queue is
   * closed and empty.
   */
  bool Pop();

  /**
   * @brief Retrieves the front element of the queue without popping it.
   *
   * @return A reference to the front element of the queue.
   * @throws std::runtime_error if the queue is empty.
   */
  const T &Front();

  /**
   * @brief Returns the current number of elements in the queue.
   *
   * @return The number of elements currently in the queue.
   */
  size_t Size();

  /**
   * @brief Checks if the queue is empty.
   *
   * @return true if the queue is empty; false otherwise.
   */
  bool IsEmpty();

  /**
   * @brief Checks if the queue is full.
   *
   * @return true if the queue is full; false otherwise.
   */
  bool IsFull();

  /**
   * @brief Checks if the queue is closed and empty.
   *
   * @return true if the queue is closed and no elements are pending; false
   * otherwise.
   */
  bool IsFinished();

  /**
   * @brief Closes the queue, preventing further pushes.
   *
   * After closing, the queue can only be popped until empty.
   */
  void Close();

  /**
   * @brief Prints the current state of the queue to standard output.
   *
   * Outputs the elements in the queue, its size, and other relevant statistics.
   */
  void Print();

private:
  size_t capacity_;
  T *elements_;
  std::atomic<long long> push_cursor_;
  std::atomic<long long> pop_cursor_;
  std::atomic<long long> elements_popped_;
  std::atomic<long long> elements_pushed_;
  std::atomic<bool> is_closed_;

  /**
   * @brief Retrieves the front element of the queue without popping it.
   *
   * Assumes the caller holds the mutex lock.
   *
   * @return A reference to the front element of the queue.
   * @throws std::runtime_error if the queue is empty.
   */
  const T &front();

  /**
   * @brief Returns the current number of elements in the queue.
   *
   * Assumes the caller holds the mutex lock.
   *
   * @return The number of elements currently in the queue.
   */
  size_t size();

  /**
   * @brief Checks if the queue is empty.
   *
   * Assumes the caller holds the mutex lock.
   *
   * @return true if the queue is empty; false otherwise.
   */
  bool is_empty();

  /**
   * @brief Checks if the queue is full.
   *
   * Assumes the caller holds the mutex lock.
   *
   * @return true if the queue is full; false otherwise.
   */
  bool is_full();

  /**
   * @brief Checks if the queue is closed and empty.
   *
   * Does not lock the mutex; intended for use within other locked methods.
   *
   * @return true if the queue is closed and empty; false otherwise.
   */
  bool is_finished();

  /**
   * @brief Marks the queue as closed for further pushes.
   *
   * Does not notify waiting threads; intended for use within `Close()` method.
   */
  void close();

  std::allocator<T> allocator_;
};

#include "circular_queue_lock_free_acq_rel.cpp"