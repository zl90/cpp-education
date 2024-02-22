#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N = 1000000;
int a[1000000];

void setup() {
  for (int i = 0; i < N; i++) {
    a[i] = rand();
  }

  std::sort(a, a + N);
}

int query() {
  int checksum = 0;

  for (int i = 0; i < N; i++) {
    int idx = std::lower_bound(a, a + N, rand()) - a;
    checksum += idx;
  }

  return checksum;
}

int main() {
  srand(time(NULL));

  setup();

  query();

  return 0;
}