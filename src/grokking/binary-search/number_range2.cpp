using namespace std;

#include <iostream>
#include <vector>

class FindRange {
public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result(-1, -1);
    if (arr.empty())
      return result;
    int a = 0, b = arr.size() - 1;
    while (a <= b) {
      int middle = (a + b) / 2;
      if (arr[middle] >= key) {
        b = middle - 1;
      } else {
        a = middle + 1;
      }
    }
    if (arr[a] != key) {
      return result;
    }
    result.first = a;
    a = a + 1;
    b = arr.size() - 1;
    while (a <= b) {
      int middle = (a + b) / 2;
      if (arr[middle] <= key) {
        a = middle + 1;
      } else {
        b = middle - 1;
      }
    }
    result.second = b;
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
