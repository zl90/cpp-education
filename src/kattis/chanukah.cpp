// https://open.kattis.com/problems/chanukah

#include <iostream>
using namespace std;

int main() {
  int P;
  cin >> P;

  for (int i = 0; i < P; i++) {
    double total_candles;
    int k, N;
    cin >> k >> N;

    // Using the sum of arithmetic series formula: (n/2)(1+n)
    total_candles = (N / 2.0) * (1 + N) + N;

    int output = total_candles;

    cout << k << ' ' << output << '\n';
  }
}