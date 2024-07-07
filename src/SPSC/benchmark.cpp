#include "circular_queue_thread_safe.hpp"

int main() {
  srand(time(NULL));

  CircularQueue<int> q(10);

  long num_elements = 1000000;
  auto start = std::chrono::high_resolution_clock::now();

  auto push_thread = [&]() {
    for (int i = 0; i < num_elements; i++) {
      q.Push(i);
    }
    q.Close();
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1ms);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    auto duration_seconds = duration.count() / 1'000'000.0;

    std::cout << "Time to push " << num_elements
              << " elements: " << duration.count() << " microseconds. ("
              << num_elements / duration_seconds << " ops/second)\n";
  };

  // Consumes until the producer signals end of input
  auto pop_thread = [&]() {
    while (!q.IsFinished()) {
      q.Pop();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    auto duration_seconds = duration.count() / 1'000'000.0;

    std::cout << "Time to pop " << num_elements
              << " elements: " << duration.count() << " microseconds. ("
              << num_elements / duration_seconds << " ops/second)\n";
  };

  std::thread t1(push_thread);
  std::thread t2(pop_thread);
  t1.join();
  t2.join();

  q.Print();
}