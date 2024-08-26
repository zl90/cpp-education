using namespace std;

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

class SmallestRange {
 public:
  static pair<int, int> findSmallestRange(const vector<vector<int>> &nums) {
    pair<int, int> range = make_pair(-1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, ValueCompare>
        minHeap;
    int N = nums.size();
    vector<int> colPointers(N, 0);
    int maxLargest = nums[0][0];
    for (int i = 0; i < N; i++) {
      minHeap.push({nums[i][0], i});
      maxLargest = max(maxLargest, nums[i][0]);
    }
    range.first = minHeap.top().first;
    range.second = maxLargest;
    while (minHeap.size() == N) {
      pair<int, int> currPair = minHeap.top();
      minHeap.pop();
      int row = currPair.second;
      colPointers[row]++;
      if (colPointers[row] < nums[row].size()) {
        minHeap.push({nums[row][colPointers[row]], row});
        maxLargest = max(maxLargest, nums[row][colPointers[row]]);
        if (maxLargest - minHeap.top().first < range.second - range.first) {
          range.first = minHeap.top().first;
          range.second = maxLargest;
        }
      }
    }
    return range;
  }

 private:
  struct ValueCompare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
      return a.first > b.first;
    }
  };
};

int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{1, 5, 8}, {4, 12}, {7, 8, 10}};
  auto result = SmallestRange::findSmallestRange(lists);
  cout << "Smallest range is: [" << result.first << ", " << result.second
       << "]";
}
