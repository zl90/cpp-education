// https://usaco.org/index.php?page=viewproblem2&cpid=891

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
  freopen("shell.in", "r", stdin);

  int n;
  cin >> n;

  vector<int> shells = {0, 1, 2};
  vector<int> count(3, 0);

  for (int i = 0; i < n; i++) {
    int a, b, g;
    cin >> a >> b >> g;
    a--, b--, g--;

    swap(shells[a], shells[b]);

    count[shells[g]]++;
  }

  freopen("shell.out", "w", stdout);

  cout << max({count[0], count[1], count[2]});
}
