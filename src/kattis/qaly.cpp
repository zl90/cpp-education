// https://open.kattis.com/problems/qaly

#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  double sum = 0;

  for (int i = 0; i < N; i++) {
    double a, b;
    cin >> a >> b;
    sum += a * b;
  }

  cout << sum;
}