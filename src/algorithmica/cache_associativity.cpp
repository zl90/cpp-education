#include <chrono>
#include <iostream>

int main() {
  constexpr long N = 1 << 21;
  int *a = new int[N];

  auto t0 = std::chrono::system_clock::now();
  for (int i = 0; i < N; i += 100) {
    a[i]++;
  }
  auto t1 = std::chrono::system_clock::now();

  std::cout
      << "100 stride incrementing loop. Time to complete: "
      << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
      << "ms\n";

  t0 = std::chrono::system_clock::now();
  for (int i = 0; i < 2097152; i += 1) {
    a[i]++;
  }
  t1 = std::chrono::system_clock::now();

  std::cout
      << "256 stride incrementing loop. Time to complete: "
      << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
      << "ms\n";

  t0 = std::chrono::system_clock::now();
  for (int i = 0; i < N; i += 257) {
    a[i]++;
  }
  t1 = std::chrono::system_clock::now();

  std::cout
      << "257 stride incrementing loop. Time to complete: "
      << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
      << "ms\n";

  delete[] a;

  return 0;
}