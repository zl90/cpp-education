using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KClosestElements {
 public:
  static vector<int> findClosestElements(const vector<int>& arr, int K, int X) {
    if (arr.empty() || K > arr.size()) return arr;
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareDistance>
        minHeap;
    vector<int> result;
    int a = 0, b = arr.size() - 1, closestX = -1;
    while (a <= b) {
      int middle = (a + b) / 2;
      if (arr[middle] == X) {
        closestX = middle;
        break;
      } else if (arr[middle] < X) {
        a = middle + 1;
      } else {
        b = middle - 1;
      }
    }
    if (closestX == -1) closestX = b;
    a = max(closestX - K + 1, 0);
    b = min(closestX + K - 1, (int)arr.size() - 1);
    while (a <= b) {
      minHeap.push({arr[a], abs(X - arr[a])});
      a++;
    }
    for (int i = 0; i < K; i++) {
      result.push_back(minHeap.top().first);
      minHeap.pop();
    }
    sort(result.begin(), result.end());
    return result;
  }

 private:
  struct CompareDistance {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
      return a.second > b.second;
    }
  };
};

int main(int argc, char* argv[]) {
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
