using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
 public:
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    if (nums.empty()) return {};
    vector<int> results;
    priority_queue<int> heap;
    for (const auto& element : nums) {
      heap.push(element);
    }
    int heapSize = heap.size();
    for (int i = 0; i < min(k, heapSize); i++) {
      results.push_back(heap.top());
      heap.pop();
    }
    return results;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result =
      KLargestNumbers::findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result =
      KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 5, 5, 5}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
