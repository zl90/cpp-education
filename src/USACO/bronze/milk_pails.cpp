// https://usaco.org/index.php?page=viewproblem2&cpid=615

#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, M;
  cin >> X >> Y >> M;

  int highest = 0;
  int max_X_pours = (M / X) + 1;
  int max_Y_pours = (M / Y) + 1;

  /*
  ---SAMPLE INPUT:
  17 25 77

  ---DESK CHECKING:
  highest: 75
  max_X_pours = 77 / 17 = 4
  max_Y_pours = 77 / 25 = 3

  25 25 25
  17 25 25 25
  17 17 25 25
  17 17 17 25
  17 17 17 17

  */

  for (int x = 0; x < max_X_pours; x++) {
    if (x * X > M) {
      break;
    }
    for (int y = 0; y < max_Y_pours; y++) {
      int total = (x * X) + (y * Y);
      if (total > M) {
        break;
      }
      highest = max(highest, total);
    }
  }

  cout << highest;
}
