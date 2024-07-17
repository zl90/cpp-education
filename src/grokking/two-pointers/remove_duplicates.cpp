using namespace std;

#include <iostream>
#include <vector>

/*
    - Naive solution O(n^2): maintain duplicate array arr2. For every element in
   arr, push it to arr2 only if it doesn't exist in arr2. This will require
   checking every element of arr2 for every element of arr.
        - Inneficiencies: O(n) space completixy and O(n^2) time complexity. I
   can improve on both.
    - Optimized solution O(n) time, O(1) space: use two pointers (left and
   right).
        - start with left and right at index 0; count++;
        - loop while right < arr.size():
            - increment right;
            - if arr[left] == arr[right]: increment right; else set left =
   right, count++;
*/

class RemoveDuplicates {
public:
  static int remove(vector<int> &&arr) {
    if (arr.size() == 0)
      return 0;

    int count = 1, left = 0, right = 0;
    while (right < arr.size()) {
      if (arr[left] != arr[right]) {
        count++;
        left = right;
      }
      right++;
    }

    return count;
  }
};

int main() {
  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};

  auto result = RemoveDuplicates::remove(move(arr));

  if (result == 4) {
    cout << "Test1 PASSED\n";
  } else {
    cout << "Test1 FAILED...\n";
  }

  arr = {9, 9, 9};
  result = RemoveDuplicates::remove(move(arr));

  if (result == 1) {
    cout << "Test2 PASSED\n";
  } else {
    cout << "Test2 FAILED...\n";
  }

  arr = {2};
  result = RemoveDuplicates::remove(move(arr));

  if (result == 1) {
    cout << "Test3 PASSED\n";
  } else {
    cout << "Test3 FAILED...\n";
  }

  arr = {};
  result = RemoveDuplicates::remove(move(arr));

  if (result == 0) {
    cout << "Test4 PASSED\n";
  } else {
    cout << "Test4 FAILED...\n";
  }

  arr = {8, 8, 6, 3, 3, 1, 1, 1};
  result = RemoveDuplicates::remove(move(arr));

  if (result == 4) {
    cout << "Test5 PASSED\n";
  } else {
    cout << "Test5 FAILED...\n";
  }
}
