// https://usaco.org/index.php?page=viewproblem2&cpid=665

#include <bits/stdc++.h>
using namespace std;

int main() {
  /*
  SAMPLE INPUT:

  5
  1 3 4 5 2
  1234567 2222222 3333333 4444444 5555555

  SAMPLE OUTPUT:

  1234567
  5555555
  2222222
  3333333
  4444444
  */

  const int SHUFFLE_NUM = 3;

  int N;
  cin >> N;

  vector<int> output{N};
  vector<int> shuffle{N};
  vector<int> ids{N};

  for (int i = 0; i < N; i++) {
    cin >> shuffle[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> ids[i];
  }

  for (int k = 0; k < SHUFFLE_NUM; k++) {
    for (int i = 0; i < N; i++) {
      output[shuffle[i] - 1] = ids[i];
    }
  }

  for (int i = 0; i < N; i++) {
    cout << output[i] << '\n';
  }
}
