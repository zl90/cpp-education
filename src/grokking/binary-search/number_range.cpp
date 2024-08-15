using namespace std;

#include <iostream>
#include <vector>

class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result(-1, -1);
    if (arr.empty()) return result;
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int middle = (start + end) / 2;
      if (arr[middle] >= key) {
        end = middle - 1;
      } else {
        start = middle + 1;
      }
    }
    if (arr[start] != key) return result;
    result.first = start;
    start = 0, end = arr.size() - 1;
    while (start <= end) {
      int middle = (start + end) / 2;
      if (arr[middle] <= key) {
        start = middle + 1;
      } else {
        end = middle - 1;
      }
    }
    result.second = end;
    return result;
  }
};

int main(int argc, char *argv[]) {
  pair<int, int> result = FindRange::findRange(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;

  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;

  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
}
