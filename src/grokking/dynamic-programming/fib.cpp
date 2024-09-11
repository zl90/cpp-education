using namespace std;
#include <iostream>

int fib(const int& N) {
  if (N <= 1) return N;
  return fib(N - 1) + fib(N - 2);
}

int main() {
  int a = 10, b = 5, c = 30;
  printf("Fib (%d): %d\n", a, fib(a));
  printf("Fib (%d): %d\n", b, fib(b));
  printf("Fib (%d): %d\n", c, fib(c));
}