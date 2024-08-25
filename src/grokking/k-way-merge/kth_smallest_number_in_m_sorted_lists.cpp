using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInMSortedArrays {
 public:
  static int findKthSmallest(const vector<vector<int>>& lists, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, ValueCompare>
        minHeap;
    int M = lists.size();
    for (int i = 0; i < M; i++) {
      if (lists[i].size() > 0) {
        minHeap.push({lists[i][0], i});
      }
    }
    vector<int> listPointers(M, 0);
    for (int i = 0; i < k - 1; i++) {
      pair<int, int> currPair = minHeap.top();
      minHeap.pop();
      int index = currPair.second;
      listPointers[index]++;
      if (listPointers[index] < lists[index].size()) {
        minHeap.push({lists[index][listPointers[index]], index});
      }
      if (minHeap.empty()) {
        return currPair.first;
      }
    }
    return minHeap.top().first;
  }

 private:
  struct ValueCompare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
      return a.first > b.first;
    }
  };
};

int main(int argc, char* argv[]) {
  vector<vector<int>> lists = {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}};
  int result = KthSmallestInMSortedArrays::findKthSmallest(lists, 5);
  cout << "Kth smallest number is: " << result << '\n';

  lists = {{5, 8, 9}, {1, 7}};
  result = KthSmallestInMSortedArrays::findKthSmallest(lists, 3);
  cout << "Kth smallest number is: " << result << '\n';

  lists = {{5, 8, 9}, {1, 7}, {}, {10, 11}};
  result = KthSmallestInMSortedArrays::findKthSmallest(lists, 90);
  cout << "Kth smallest number is: " << result << '\n';
}
