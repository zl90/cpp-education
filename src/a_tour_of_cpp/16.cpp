#include <chrono>
#include <iostream>
#include <memory>

template <typename T> class Smart_pointer {
  T &operator*() const;
  T *operator->() const
    requires std::is_class_v<T>;
};

int main() {
  // Tracking time with std::chrono:
  auto t0 = std::chrono::system_clock::now();
  for (int i = 0; i < 100000000; i++) {
    int j = 55;
  }
  auto t1 = std::chrono::system_clock::now();

  // std::cout << t1 - t0 << '\n';
  std::cout
      << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
      << "ms\n";
  std::cout
      << std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count()
      << "ns\n";

  // Using std::move()
  auto p = std::make_unique<int>(2);
  // auto q = p;         // Error, cannot copy unique_ptr
  auto q = std::move(p); // OK: Can move unique_ptr

  return 0;
}