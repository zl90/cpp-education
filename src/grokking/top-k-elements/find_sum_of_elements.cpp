using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SumOfElements {
 public:
  static int findSumOfElements(const vector<int> &nums, int k1, int k2) {
    int elementSum = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < nums.size(); i++) {
      if (i < k2) {
        minHeap.push(nums[i]);
      } else if (nums[i] > minHeap.top()) {
        minHeap.pop();
        minHeap.push(nums[i]);
      }
    }
    for (int i = 0; i < k2 - 1; i++) {
      if (i >= k1) {
        elementSum += minHeap.top();
      }
      minHeap.pop();
    }
    return elementSum;
  }
};

int main(int argc, char *argv[]) {
  int result =
      SumOfElements::findSumOfElements(vector<int>{1, 3, 12, 5, 15, 11}, 3, 6);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result
       << endl;

  result = SumOfElements::findSumOfElements(vector<int>{3, 5, 8, 7}, 1, 4);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result
       << endl;
}
