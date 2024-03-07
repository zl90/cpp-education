// https://open.kattis.com/problems/metronome

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  float n = atof(input.c_str());

  cout << fixed << setprecision(2) << n / 4.0;
}