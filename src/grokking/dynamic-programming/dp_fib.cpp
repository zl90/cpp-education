using namespace std;
#include <iostream>

int dp_fib(const int &N) {
  if (N <= 1)
    return N;

  pair<int, int> prev = {0, 1};
  for (int i = 2; i <= N; i++) {
    int curr = prev.first + prev.second;
    prev.first = prev.second;
    prev.second = curr;
  }
  return prev.second;
}

int main() {
  int a = 10, b = 5, c = 42;
  printf("Fib (%d): %d\n", a, dp_fib(a));
  printf("Fib (%d): %d\n", b, dp_fib(b));
  printf("Fib (%d): %d\n", c, dp_fib(c));
}