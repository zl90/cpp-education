using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SubarrayProductLessThanK {
 public:
  static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
    vector<vector<int>> result;
    int runningProduct = 1, a = 0;
    queue<int> subArray;
    for (int b = 0; b < arr.size(); b++) {
      if (arr[b] < target) result.push_back({arr[b]});
      runningProduct *= arr[b];
      subArray.push(arr[b]);
      while (runningProduct >= target) {
        runningProduct /= arr[a];
        subArray.pop();
        a++;
      }
      if (a != b) {
        vector<int> output;
        queue<int> subArrayCopy = subArray;
        while (!subArrayCopy.empty()) {
          output.push_back(subArrayCopy.front());
          subArrayCopy.pop();
        }
        result.push_back(output);
      }
    }
    return result;
  }
};

int main() {
  vector<int> arr{2, 5, 3, 10};
  int target = 30;

  auto result = SubarrayProductLessThanK::findSubarrays(arr, target);

  for (const auto& subarray : result) {
    std::cout << "[";
    for (const auto& element : subarray) {
      std::cout << element << ", ";
    }
    std::cout << "], ";
  }

  std::cout << "\n";

  arr = {8, 2, 6, 5};
  target = 50;

  result = SubarrayProductLessThanK::findSubarrays(arr, target);

  for (const auto& subarray : result) {
    std::cout << "[";
    for (const auto& element : subarray) {
      std::cout << element << ", ";
    }
    std::cout << "], ";
  }

  std::cout << "\n";
}