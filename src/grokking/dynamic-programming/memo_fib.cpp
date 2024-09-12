using namespace std;
#include <iostream>
#include <unordered_map>

int memo_fib(int N, unordered_map<int, int> &cache) {
  if (N <= 1)
    return N;
  if (cache[N] > 1)
    return cache[N];
  cache[N] = memo_fib(N - 1, cache) + memo_fib(N - 2, cache);
  return cache[N];
}

int main() {
  int a = 10, b = 5, c = 42;
  unordered_map<int, int> cache1;
  unordered_map<int, int> cache2;
  unordered_map<int, int> cache3;
  printf("MemoFib (%d): %d\n", a, memo_fib(a, cache1));
  printf("MemoFib (%d): %d\n", b, memo_fib(b, cache2));
  printf("MemoFib (%d): %d\n", c, memo_fib(c, cache3));
}