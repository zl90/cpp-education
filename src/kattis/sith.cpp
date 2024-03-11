// https://open.kattis.com/problems/sith

#include <iostream>
#include <string>
using namespace std;

int main() {
  int a, b, x;
  string name;
  getline(cin, name);
  cin >> a;
  cin >> b;
  cin >> x;

  if ((a - b) < 0) {
    if (x < 0) {
      cout << "JEDI";
    } else {
      cout << "SITH";
    }
  } else {
    cout << "VEIT EKKI";
  }
}