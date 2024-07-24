using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class ReplacingOnes {
 public:
  static int findLength(const string& arr, int k) {
    if (k >= arr.size()) return arr.size();
    int longest = 0, a = 0, sum = 0;
    for (int b = 0; b < arr.size(); b++) {
      sum += arr[b];
      while (b - a + 1 - sum > k) {
        sum -= arr[a];
        a++;
      }
      longest = max(longest, b - a + 1);
    }
    return longest;
  }
};

int main() {
  int result = ReplacingOnes::findLength({0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2);
  cout << result << "\n";  // 6
  result =
      ReplacingOnes::findLength({0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3);
  cout << result << "\n";  // 9
  result = ReplacingOnes::findLength({0, 1}, 3);
  cout << result << "\n";  // 2
  result = ReplacingOnes::findLength({}, 3);
  cout << result << "\n";  // 0
}