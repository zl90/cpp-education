// https://open.kattis.com/problems/millifaersla

#include <iostream>
#include <string>
using namespace std;

int main() {
  string service_names[] = {"Monnei", "Fjee", "Dolladollabilljoll"};
  int fees[3];

  string input;
  getline(cin, input);
  fees[0] = atoi(input.c_str());
  getline(cin, input);
  fees[1] = atoi(input.c_str());
  getline(cin, input);
  fees[2] = atoi(input.c_str());

  int lowest_fee = fees[0];
  int lowest_fee_index = 0;

  for (int i = 1; i < 3; i++) {
    if (fees[i] < lowest_fee) {
      lowest_fee = fees[i];
      lowest_fee_index = i;
    }
  }

  cout << service_names[lowest_fee_index];
}