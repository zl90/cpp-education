// Learning atomic operations and memory ordering
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::vector<int> vec{3};
std::atomic<bool> is_ready_to_read = false;

void thread1_func() {
  // put data into the vector
  vec[0] = 123;
  vec[1] = 234;
  vec[2] = 345;
  // signal that the data has been put in
  std::cout << "Vector is now ready...\n";
  is_ready_to_read.store(true, std::memory_order_seq_cst);
  // anything in here is not guaranteed to be ordered
}

void thread2_func() {
  // wait for the data to be put in the vector
  while (!is_ready_to_read.load(std::memory_order_seq_cst))
    ;
  // read from the vector
  std::cout << "First element is: " << vec[0] << '\n';
}

int main() {
  std::thread t1(thread1_func);
  std::thread t2(thread2_func);
  t1.join();
  t2.join();
}