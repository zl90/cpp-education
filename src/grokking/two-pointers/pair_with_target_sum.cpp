#include <iostream>
#include <vector>

/*
    - Is the vector sorted in ascending or descending order?
    - Is there always guaranteed to be an answer?
    - Can the integers be negative?
*/

using namespace std;

class PairWithTargetSum {
public:
  static pair<int, int> search(const vector<int> &arr, int targetSum) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
      if (arr[left] + arr[right] == targetSum) {
        break;
      } else if (arr[left] + arr[right] > targetSum) {
        right--;
      } else if (arr[left] + arr[right] < targetSum) {
        left++;
      }
    }

    return make_pair(left, right);
  }
};

int main() {
  int targetSum = 12;
  vector<int> arr = {3, 4, 8, 11};

  auto result = PairWithTargetSum::search(arr, targetSum);

  if (result.first == 1 && result.second == 2) {
    cout << "Test1 PASSED\n";
  } else {
    cout << "Test1 FAILED...\n";
  }

  targetSum = 19;
  result = PairWithTargetSum::search(arr, targetSum);

  if (result.first == 2 && result.second == 3) {
    cout << "Test2 PASSED\n";
  } else {
    cout << "Test2 FAILED...\n";
  }

  targetSum = 14;
  result = PairWithTargetSum::search(arr, targetSum);

  if (result.first == 0 && result.second == 3) {
    cout << "Test3 PASSED\n";
  } else {
    cout << "Test3 FAILED...\n";
  }
}
