using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KClosestElements {
 public:
  struct numCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.first > y.first;
    }
  };

  static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, numCompare> minHeap;
    for (int i = 0; i < arr.size(); i++) {
      if (i < K) {
        minHeap.push({arr[i], abs(X - arr[i])});
      } else if (abs(X - arr[i]) < minHeap.top().second) {
        minHeap.pop();
        minHeap.push({arr[i], abs(X - arr[i])});
      }
    }
    int heapSize = minHeap.size();
    for (int i = 0; i < heapSize; i++) {
      result.push_back(minHeap.top().first);
      minHeap.pop();
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result =
      KClosestElements::findClosestElements(vector<int>{5, 6, 7, 8, 9}, 3, 7);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result =
      KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 6);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
