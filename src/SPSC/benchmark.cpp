#include "circular_queue_lock_free.hpp"
#include "circular_queue_lock_free_acq_rel.hpp"
#include "circular_queue_lock_free_acq_rel_alignas.hpp"
#include "circular_queue_thread_safe.hpp"
#include "circular_queue_thread_safe_prealloc.hpp"

int main() {
  srand(time(NULL));

  CircularQueue<int> thread_safe_circular_queue(10);

  long num_elements = 10000000;
  auto start = std::chrono::high_resolution_clock::now();

  auto push_thread = [&]() {
    for (int i = 0; i < num_elements; i++) {
      thread_safe_circular_queue.Push(i);
    }
    thread_safe_circular_queue.Close();
  };

  // Consumes until the producer signals end of input
  auto pop_thread = [&]() {
    while (!thread_safe_circular_queue.IsFinished()) {
      thread_safe_circular_queue.Pop();
    }
  };

  std::thread t1(push_thread);
  std::thread t2(pop_thread);
  t1.join();
  t2.join();

  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  auto duration_seconds = duration.count() / 1'000'000.0;

  std::cout << "**** Thread safe circular queue ****\nTime to push & pop "
            << num_elements << " elements: " << duration.count()
            << " microseconds. (" << num_elements / duration_seconds
            << " ops/second)\n";

  thread_safe_circular_queue.Print();

  CircularQueuePreAlloc<int> thread_safe_circular_queue_prealloc(10);

  start = std::chrono::high_resolution_clock::now();

  auto push_thread_prealloc = [&]() {
    for (int i = 0; i < num_elements; i++) {
      thread_safe_circular_queue_prealloc.Push(i);
    }
    thread_safe_circular_queue_prealloc.Close();
  };

  // Consumes until the producer signals end of input
  auto pop_thread_prealloc = [&]() {
    while (!thread_safe_circular_queue_prealloc.IsFinished()) {
      thread_safe_circular_queue_prealloc.Pop();
    }
  };

  std::thread t3(push_thread_prealloc);
  std::thread t4(pop_thread_prealloc);
  t3.join();
  t4.join();

  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  duration_seconds = duration.count() / 1'000'000.0;

  std::cout << "**** Thread safe circular queue (preallocated memory) "
               "****\nTime to push & pop "
            << num_elements << " elements: " << duration.count()
            << " microseconds. (" << num_elements / duration_seconds
            << " ops/second)\n";

  thread_safe_circular_queue_prealloc.Print();

  CircularQueueLockFree<int> lock_free_circular_queue(10);

  start = std::chrono::high_resolution_clock::now();

  auto push_thread_lock_free = [&]() {
    for (int i = 0; i < num_elements; i++) {
      lock_free_circular_queue.Push(i);
    }
    lock_free_circular_queue.Close();
  };

  // Consumes until the producer signals end of input
  auto pop_thread_lock_free = [&]() {
    while (!lock_free_circular_queue.IsFinished()) {
      lock_free_circular_queue.Pop();
    }
  };

  std::thread t5(push_thread_lock_free);
  std::thread t6(pop_thread_lock_free);
  t5.join();
  t6.join();

  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  duration_seconds = duration.count() / 1'000'000.0;

  std::cout << "**** Thread safe circular queue (lock free) "
               "****\nTime to push & pop "
            << num_elements << " elements: " << duration.count()
            << " microseconds. (" << num_elements / duration_seconds
            << " ops/second)\n";

  lock_free_circular_queue.Print();

  CircularQueueLockFreeAcqRel<int> lock_free_circular_queue_acq_rel(10);

  start = std::chrono::high_resolution_clock::now();

  auto push_thread_lock_free_acq_rel = [&]() {
    for (int i = 0; i < num_elements; i++) {
      lock_free_circular_queue_acq_rel.Push(i);
    }
    lock_free_circular_queue_acq_rel.Close();
  };

  // Consumes until the producer signals end of input
  auto pop_thread_lock_free_acq_rel = [&]() {
    while (!lock_free_circular_queue_acq_rel.IsFinished()) {
      lock_free_circular_queue_acq_rel.Pop();
    }
  };

  std::thread t7(push_thread_lock_free_acq_rel);
  std::thread t8(pop_thread_lock_free_acq_rel);
  t7.join();
  t8.join();

  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  duration_seconds = duration.count() / 1'000'000.0;

  std::cout << "**** Thread safe circular queue (lock free - release acquire "
               "memory ordering) "
               "****\nTime to push & pop "
            << num_elements << " elements: " << duration.count()
            << " microseconds. (" << num_elements / duration_seconds
            << " ops/second)\n";

  lock_free_circular_queue_acq_rel.Print();

  CircularQueueLockFreeAcqRelAlignas<int>
      lock_free_circular_queue_acq_rel_alignas(10);

  start = std::chrono::high_resolution_clock::now();

  auto push_thread_lock_free_acq_rel_alignas = [&]() {
    for (int i = 0; i < num_elements; i++) {
      lock_free_circular_queue_acq_rel_alignas.Push(i);
    }
    lock_free_circular_queue_acq_rel_alignas.Close();
  };

  // Consumes until the producer signals end of input
  auto pop_thread_lock_free_acq_rel_alignas = [&]() {
    while (!lock_free_circular_queue_acq_rel_alignas.IsFinished()) {
      lock_free_circular_queue_acq_rel_alignas.Pop();
    }
  };

  std::thread t9(push_thread_lock_free_acq_rel_alignas);
  std::thread t10(pop_thread_lock_free_acq_rel_alignas);
  t9.join();
  t10.join();

  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  duration_seconds = duration.count() / 1'000'000.0;

  std::cout << "**** Thread safe circular queue (lock free - release acquire "
               "memory ordering - alignas) "
               "****\nTime to push & pop "
            << num_elements << " elements: " << duration.count()
            << " microseconds. (" << num_elements / duration_seconds
            << " ops/second)\n";

  lock_free_circular_queue_acq_rel_alignas.Print();
}