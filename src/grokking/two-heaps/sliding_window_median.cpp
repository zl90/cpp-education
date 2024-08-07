using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class SlidingWindowMedian {
 public:
  virtual vector<double> findSlidingWindowMedian(const vector<int> &nums,
                                                 int k) {
    vector<double> result;
    priority_queue<int> maxSmallest;
    priority_queue<int, vector<int>, greater<int>> minLargest;
    int a = 0;
    for (int b = 0; b < nums.size(); b++) {
      if (maxSmallest.empty() || nums[b] < maxSmallest.top()) {
        maxSmallest.push(nums[b]);
      } else {
        minLargest.push(nums[b]);
      }
      if (maxSmallest.size() > minLargest.size() + 1) {
        minLargest.push(maxSmallest.top());
        maxSmallest.pop();
      } else if (minLargest.size() > maxSmallest.size() + 1) {
        maxSmallest.push(minLargest.top());
        minLargest.pop();
      }
      if (b > k - 1) {
        if (nums[a] <= maxSmallest.top()) {
          // remove element from maxSmallest
        } else {
          // remove element from minLargest
        }
        a++;
      }
      if (b >= k - 1) {
        if (maxSmallest.size() == minLargest.size()) {
          result.push_back((maxSmallest.top() + minLargest.top()) / 2.0);
        } else if (maxSmallest.size() > minLargest.size()) {
          result.push_back(maxSmallest.top());
        } else {
          result.push_back(minLargest.top());
        }
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  SlidingWindowMedian slidingWindowMedian;
  vector<double> result = slidingWindowMedian.findSlidingWindowMedian(
      vector<int>{1, 2, -1, 3, 5}, 2);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  slidingWindowMedian = SlidingWindowMedian();
  result = slidingWindowMedian.findSlidingWindowMedian(
      vector<int>{1, 2, -1, 3, 5}, 3);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
