using namespace std;

#include <iostream>
#include <vector>

class DutchFlag {
 public:
  static void sort(vector<int>& arr) {
    if (arr.size() <= 1) {
      return;
    }

    for (int target = 0; target < 2; target++) {
      int a = 0, b = arr.size() - 1;
      while (a < b) {
        if (arr[a] <= target) {
          a++;
        } else {
          if (arr[b] == target) {
            swap(arr[a], arr[b]);
            a++;
          } else {
            b--;
          }
        }
      }
    }
  }
};

int main() {
  vector<int> arr{1, 0, 2, 1, 0};

  DutchFlag::sort(arr);

  for (const auto& element : arr) {
    std::cout << element << ", ";
  }

  std::cout << "\n";

  arr = {0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};

  DutchFlag::sort(arr);

  for (const auto& element : arr) {
    std::cout << element << ", ";
  }

  std::cout << "\n";

  arr = {2};

  DutchFlag::sort(arr);

  for (const auto& element : arr) {
    std::cout << element << ", ";
  }

  std::cout << "\n";
}