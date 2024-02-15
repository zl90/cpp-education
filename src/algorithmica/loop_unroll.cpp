// Learning assembly.
// Testing loop unrolling.

int loop_unroll() {
  int result = 0;
  for (int i = 0; i < 20; i++) {
    result += i;
  }
  return result;
}

int main() {
  loop_unroll();

  return 0;
}