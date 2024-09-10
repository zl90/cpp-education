using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ConnectRopes {
 public:
  static int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
    if (ropeLengths.size() <= 1) return 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int result = 0;
    for (const auto &ropeLength : ropeLengths) {
      minHeap.push(ropeLength);
    }
    while (minHeap.size() > 1) {
      int first = minHeap.top();
      minHeap.pop();
      int second = minHeap.top();
      minHeap.pop();
      int sum = first + second;
      result += sum;
      minHeap.push(sum);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  int result =
      ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{3, 4, 5, 6});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5, 2});
  cout << "Minimum cost to connect ropes: " << result << endl;
}
