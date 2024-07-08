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
}