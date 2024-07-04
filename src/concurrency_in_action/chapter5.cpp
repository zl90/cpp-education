// Learning atomic operations and memory ordering
#include <assert.h>
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
  while (!is_ready_to_read.load(
      std::memory_order_seq_cst)) // All memory writes before the store in
                                  // thread1_func will be visible to this
                                  // thread, and the order of those writes are
                                  // maintained in a global order for all
                                  // threads.
    ;
  // read from the vector
  std::cout << "First element is: " << vec[0] << '\n';
}

void exercise_1() {
  // Learning how to use atomic bools + learning what the "synchronizes-with"
  // and "happens-before" relationships are
  std::thread t1(thread1_func);
  std::thread t2(thread2_func);
  t1.join();
  t2.join();
}

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x() {
  std::cout << "Writing to x...\n";
  x.store(true, std::memory_order_seq_cst);
}
void write_y() {
  std::cout << "Writing to y...\n";
  y.store(true, std::memory_order_seq_cst);
}

void read_x_then_y() {
  while (!x.load(std::memory_order_seq_cst))
    ;
  if (y.load(std::memory_order_seq_cst)) {
    std::cout << "Incrementing z... x is true!\n";
    z++;
  }
}

void read_y_then_x() {
  while (!y.load(std::memory_order_seq_cst))
    ;
  if (x.load(std::memory_order_seq_cst)) {
    std::cout << "Incrementing z... y is true!\n";
    z++;
  }
}

void exercise_2() {
  // Learning about std::memory_order_seq_cst
  x = false;
  y = false;
  z = 0;
  std::thread t1(write_x);
  std::thread t2(write_y);
  std::thread t3(read_x_then_y);
  std::thread t4(read_y_then_x);
  t1.join();
  t2.join();
  t3.join();
  t4.join();

  assert(z.load(std::memory_order_seq_cst) != 0);
}

void write_x_then_y() {
  // There is no guarantee that this write order will appear the same in other
  // threads! There is a very real possibility that another thread could see x
  // as false and y as true, even though they have a happens-before
  // relationship in this thread.
  std::cout << "Writing to x and y...\n";
  x.store(true, std::memory_order_relaxed);
  y.store(true, std::memory_order_relaxed);
}

void read_y_then_x_2() {
  while (!y.load(std::memory_order_relaxed))
    ;
  if (x.load(std::memory_order_relaxed)) {
    std::cout << "Incrementing z... y is true!\n";
    z++;
  }
}

void exercise_3() {
  // Learning about std::memory_order_relaxed.
  // std::memory_order_relaxed doesn't participate in synchronizes-with
  // relationships.
  x = false;
  y = false;
  z = 0;
  std::thread t3(write_x_then_y);
  std::thread t4(read_y_then_x_2);
  t3.join();
  t4.join();

  assert(z.load() != 0);
}

void write_x_then_y_4() {
  std::cout << "Writing to x and y...!\n";
  x.store(true, std::memory_order_relaxed);
  y.store(true, std::memory_order_release);
}

void read_y_then_x_4() {
  while (!y.load(
      std::memory_order_acquire)) // All memory writes before the y.store in the
                                  // write_x_then_y_4 thread will become visible
                                  // to this thread (aka: the y store
                                  // synchronizes with the y load). The order of
                                  // the writes are not stored globally though,
                                  // and other threads could see x as false and
                                  // y as true.
    ;
  if (x.load(std::memory_order_relaxed))
    std::cout << "Incrementing z... x is true!\n";
  ++z;
}

void exercise_4() {
  // Learning about std::memory_order_release and std::memory_order_acquire.
  // Now there IS a synchronizes-with relationship for stores within the same
  // thread.
  x = false;
  y = false;
  z = 0;
  std::thread t3(write_x_then_y_4);
  std::thread t4(read_y_then_x_4);
  t3.join();
  t4.join();

  assert(z.load() != 0);
}

int main() {
  // exercise_1();
  // exercise_2();
  // exercise_3();
  exercise_4();
}