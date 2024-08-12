using namespace std;

#include <iostream>
#include <vector>

class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    if (arr.empty()) return -1;
    if (arr.front() == arr.back()) {
      if (arr.front() == key) {
        return 0;
      }
      return -1;
    }
    bool isAscending = arr.front() < arr.back();
    if (isAscending) {
      return searchAscending(arr, 0, arr.size() - 1, key);
    } else {
      return searchDescending(arr, 0, arr.size() - 1, key);
    }
  }

 private:
  static int searchAscending(const vector<int>& arr, int start, int end,
                             int key) {
    int index = (start + end) / 2;
    int element = arr[index];
    if (element == key) return index;
    if (start == end) return -1;
    if (element < key) {
      return searchAscending(arr, index + 1, end, key);
    } else {
      return searchAscending(arr, start, index - 1, key);
    }
  }

  static int searchDescending(const vector<int>& arr, int start, int end,
                              int key) {
    int index = (start + end) / 2;
    int element = arr[index];
    if (element == key) return index;
    if (start == end) return -1;
    if (element < key) {
      return searchDescending(arr, start, index - 1, key);
    } else {
      return searchDescending(arr, index + 1, end, key);
    }
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}
