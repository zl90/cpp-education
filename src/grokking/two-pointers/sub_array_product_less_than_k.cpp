using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class SubarrayProductLessThanK {
 public:
  static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
    if (arr.size() == 0) return {};

    vector<vector<int>> result;
    deque<int> q;
    int a = 0, b = 0, product = 1;

    for (int b = 0; b < arr.size(); b++) {
      product *= arr[b];
      q.push_back(arr[b]);
      while (product >= target) {
        q.pop_front();
        product /= arr[a];
        a++;
      }
      result.push_back(to_array(q));
      if (q.size() > 1) {
        result.push_back({arr[b]});
      }
    }

    return result;
  }

 private:
  static vector<int> to_array(deque<int> q) {
    vector<int> result;
    while (!q.empty()) {
      result.push_back(q.front());
      q.pop_front();
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