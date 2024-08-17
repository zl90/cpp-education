using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
 public:
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    if (nums.empty()) return {};
    if (k >= nums.size()) return nums;
    vector<int> results;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < nums.size(); i++) {
      if (i < k) {
        minHeap.push(nums[i]);
      } else {
        if (nums[i] > minHeap.top()) {
          minHeap.pop();
          minHeap.push(nums[i]);
        }
      }
    }
    for (int i = 0; i < k; i++) {
      results.push_back(minHeap.top());
      minHeap.pop();
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
