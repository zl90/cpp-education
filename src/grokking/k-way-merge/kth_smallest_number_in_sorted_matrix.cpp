using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInSortedMatrix {
 public:
  static int findKthSmallest(const vector<vector<int>>& matrix, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, ValueCompare>
        minHeap;
    int N = matrix.size();
    for (int i = 0; i < N; i++) {
      if (matrix[i].size() > 0) {
        minHeap.push({matrix[i][0], i});
      }
    }
    vector<int> colPointers(N, 0);
    for (int i = 0; i < k - 1; i++) {
      pair<int, int> currPair = minHeap.top();
      minHeap.pop();
      int row = currPair.second;
      int value = currPair.first;
      colPointers[row]++;
      if (colPointers[row] < matrix[row].size()) {
        minHeap.push({matrix[row][colPointers[row]], row});
      }
      if (minHeap.empty()) {
        return value;
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
  vector<vector<int>> matrix = {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}};
  int result = KthSmallestInSortedMatrix::findKthSmallest(matrix, 5);
  cout << "Kth smallest number is: " << result << '\n';

  matrix = {{5, 8, 9}, {1, 7}};
  result = KthSmallestInSortedMatrix::findKthSmallest(matrix, 3);
  cout << "Kth smallest number is: " << result << '\n';

  matrix = {{5, 8, 9}, {1, 7}, {}, {10, 11}};
  result = KthSmallestInSortedMatrix::findKthSmallest(matrix, 90);
  cout << "Kth smallest number is: " << result << '\n';
}
