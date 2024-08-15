using namespace std;

#include <iostream>
#include <vector>

class MaxInBitonicArray {
 public:
  static int findMax(const vector<int> &arr) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int middle = (start + end) / 2;
      if (arr[middle] < arr[middle + 1]) {
        start = middle + 1;
      } else {
        end = middle - 1;
      }
    }
    return arr[start];
  }
};

int main(int argc, char *argv[]) {
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}
