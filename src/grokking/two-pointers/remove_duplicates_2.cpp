using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int> &arr) {
    if (arr.size() == 0 || arr.size() == 1) {
      return arr.size();
    }
    int a = 1;
    for (int b = 1; b < arr.size(); b++) {
      if (arr[a - 1] != arr[b]) {
        arr[a] = arr[b];
        a++;
      }
    }

    return a;
  }
};

int main() {
  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};

  auto result = RemoveDuplicates::remove(arr);

  if (result == 4) {
    cout << "Test1 PASSED\n";
  } else {
    cout << "Test1 FAILED...\n";
  }

  arr = {9, 9, 9};
  result = RemoveDuplicates::remove(arr);

  if (result == 1) {
    cout << "Test2 PASSED\n";
  } else {
    cout << "Test2 FAILED...\n";
  }

  arr = {2};
  result = RemoveDuplicates::remove(arr);

  if (result == 1) {
    cout << "Test3 PASSED\n";
  } else {
    cout << "Test3 FAILED...\n";
  }

  arr = {};
  result = RemoveDuplicates::remove(arr);

  if (result == 0) {
    cout << "Test4 PASSED\n";
  } else {
    cout << "Test4 FAILED...\n";
  }

  arr = {8, 8, 6, 3, 3, 1, 1, 1};
  result = RemoveDuplicates::remove(arr);

  if (result == 4) {
    cout << "Test5 PASSED\n";
  } else {
    cout << "Test5 FAILED...\n";
  }
}