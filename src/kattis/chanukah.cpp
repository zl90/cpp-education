// https://open.kattis.com/problems/chanukah

#include <iostream>
#include <string>
using namespace std;

int main() {
  int P;
  cin >> P;

  for (int i = 0; i < P; i++) {
    double total_candles;
    int k, N;
    cin >> k >> N;

    total_candles = (N / 2.0) * (1 + N) + N;

    int output = total_candles;

    cout << k << ' ' << to_string(output) << '\n';
  }
}