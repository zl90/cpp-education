// https://usaco.org/index.php?page=viewproblem2&cpid=855

#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("shell.in", "r", stdin);

  vector<int> capacity(3, 0);
  vector<int> milk(3, 0);

  for (int i = 0; i < 3; i++) {
    cin >> capacity[i] >> milk[i];
  }

  int a = 0;
  int b = 1;

  for (int i = 0; i < 100; i++) {
    int capacity_remaining_b = capacity[b] - milk[b];
    int pour_amount = min(milk[a], capacity_remaining_b);

    milk[a] -= pour_amount;
    milk[b] += pour_amount;

    a = (a + 1) % 3;
    b = (b + 1) % 3;
  }

  freopen("shell.out", "w", stdout);
  printf("%d\n%d\n%d", milk[0], milk[1], milk[2]);
}
