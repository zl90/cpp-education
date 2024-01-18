#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <numeric>
#include <thread>
#include <vector>

static int count = 0;

std::mutex m;

void f() {
  std::scoped_lock lock{m}; // Acquire mutex
  count = count + 1;
} // Mutex is implicitly released when lock is destructed

int factorial(int N) {
  if (N <= 1) {
    return 1;
  } else {
    return N * factorial(N - 1);
  }
}

int square(int x) { return x * x; }

double accum(std::vector<double>::iterator beg,
             std::vector<double>::iterator end, double init) {
  return std::accumulate(&*beg, &*end, init);
}

double comp4(std::vector<double> &v) {
  if (v.size() < 10'000) {
    return accum(v.begin(), v.end(), 0.0);
  }

  auto v0 = &v[0];
  auto sz = v.size();

  auto f0 = std::async(accum, v0, v0 + sz / 4, 0.0);
  auto f1 = std::async(accum, v0 + sz / 4, v0 + sz / 2, 0.0);
  auto f2 = std::async(accum, v0 + sz / 2, v0 + sz * 3 / 4, 0.0);
  auto f3 = std::async(accum, v0 + sz * 3 / 4, v0 + sz, 0.0);

  return f0.get() + f1.get() + f2.get() + f3.get();
}

int main() {
  // Making a thousand threads (note: without a mutex and a thread lock, the
  // results of the following code is non-deterministic):
  for (int j = 0; j < 20; j++) {
    std::vector<std::thread> threads;

    for (int i = 0; i < 1000; i++) {
      threads.push_back(std::thread(f));
    }

    for (int i = 0; i < 1000; i++) {
      threads[i].join();
    }

    std::cout << "Count: " << count << '\n';
    count = 0;
  }

  // Waiting inside a thread:
  auto t0 = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(std::chrono::milliseconds(20));
  auto t1 = std::chrono::high_resolution_clock::now();

  std::cout
      << std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count()
      << " nanoseconds passed\n";

  // Using async and future:
  std::future<int> asyncFunction =
      std::async(&square, 12); // Does the async function spawn a new thread??
                               // --> Depends on the launch policy.
  auto result = asyncFunction.get(); // .get() is a blocking operation

  std::cout << "Result is: " << result << '\n';

  // Using std::packaged_task:
  std::packaged_task<int(int)> pt(factorial);

  pt(10); // packaged_tasks can be used later
  int pt_result = pt.get_future().get();

  std::cout << "Result of packaged task: " << pt_result << '\n';

  std::vector<double> my_vec(20000, 1.0);

  double d_result = comp4(my_vec);

  std::cout << "Result of comp4: " << d_result << '\n';

  return 0;
}