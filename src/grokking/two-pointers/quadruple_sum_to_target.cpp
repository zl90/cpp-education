using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class QuadrupleSumToTarget {
 public:
  static vector<vector<int>> searchQuadruplets(vector<int>& arr, int target) {
    vector<vector<int>> quadruplets;
    sort(arr.begin(), arr.end());
    for (int a = 0; a < arr.size() - 3; a++) {
      for (int b = a + 1; b < arr.size() - 2; b++) {
        int c = b + 1, d = arr.size() - 1;
        while (c < d) {
          int sum = arr[a] + arr[b] + arr[c] + arr[d];
          if (sum == target) {
            if (isUniqueQuadruplet(arr[a], arr[b], arr[c], arr[d],
                                   quadruplets)) {
              quadruplets.push_back({arr[a], arr[b], arr[c], arr[d]});
            }
            c++;
          } else if (sum < target) {
            c++;
          } else {
            d--;
          }
        }
      }
    }
    return quadruplets;
  }

 private:
  static bool isUniqueQuadruplet(int a, int b, int c, int d,
                                 vector<vector<int>> quadruplets) {
    for (const auto& quadruplet : quadruplets) {
      if (a == quadruplet[0] && b == quadruplet[1] && c == quadruplet[2] &&
          d == quadruplet[3])
        return false;
    }
    return true;
  }
};

int main() {
  vector<int> arr{4, 1, 2, -1, 1, -3};  // -3 -1 1 1 2 4
  int target = 1;

  auto result = QuadrupleSumToTarget::searchQuadruplets(arr, target);

  for (const auto& subarray : result) {
    std::cout << "[";
    for (const auto& element : subarray) {
      std::cout << element << ", ";
    }
    std::cout << "], ";
  }

  std::cout << "\n";

  arr = {2, 0, -1, 1, -2, 2};
  target = 2;

  result = QuadrupleSumToTarget::searchQuadruplets(arr, target);

  for (const auto& subarray : result) {
    std::cout << "[";
    for (const auto& element : subarray) {
      std::cout << element << ", ";
    }
    std::cout << "], ";
  }

  std::cout << "\n";
}