// https://open.kattis.com/problems/triarea

#include <iostream>
#include <string>
using namespace std;

int main() {
  int height, base;
  cin >> height >> base;
  double area = 0.5f * base * height;

  cout << area;
}