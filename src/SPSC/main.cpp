#include "circular_queue_thread_safe.hpp"

int main() {
  srand(time(NULL));

  CircularQueue<int> q(10);

  // Simulates an erratic producer
  auto push_thread = [&]() {
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < (rand() % 15) + 1; j++) {
        q.Push(i);
      }
      std::this_thread::sleep_for(std::chrono::nanoseconds((rand() % 5) + 1));
    }
    q.Close();
  };

  // Consumes until the producer signals end of input
  auto pop_thread = [&]() {
    while (!q.IsFinished()) {
      q.Pop();
    }
  };

  std::thread t1(push_thread);
  std::thread t2(pop_thread);
  t1.join();
  t2.join();

  q.Print();
}