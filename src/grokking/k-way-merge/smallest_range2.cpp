using namespace std;

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

class SmallestRange {
 public:
  static pair<int, int> findSmallestRange(const vector<vector<int>> &nums) {
    int M = nums.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, ValueCompare>
        minHeap;
    vector<int> indices(M, 0);
    pair<int, int> range = make_pair(-1, -1);
    int maxNum = nums[0][0];
    for (int i = 0; i < M; i++) {
      minHeap.push({nums[i][0], i});
      maxNum = max(nums[i][0], maxNum);
    }
    range.first = minHeap.top().first;
    range.second = maxNum;
    while (minHeap.size() == M) {
      const auto currPair = minHeap.top();
      minHeap.pop();
      indices[currPair.second]++;
      if (indices[currPair.second] < nums[currPair.second].size()) {
        minHeap.push(
            {nums[currPair.second][indices[currPair.second]], currPair.second});
        maxNum = max(nums[currPair.second][indices[currPair.second]], maxNum);
        if (maxNum - minHeap.top().first < range.second - range.first) {
          range.first = minHeap.top().first;
          range.second = maxNum;
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
       << "]\n";
}
