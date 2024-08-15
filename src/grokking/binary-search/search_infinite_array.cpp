using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayReader {
 public:
  vector<int> arr;

  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

class SearchInfiniteSortedArray {
 public:
  static int search(ArrayReader *reader, int key) {
    int start = 0, end = 0, jump = 2;
    while (reader->get(end) < key) {
      start = end + 1;
      end += jump;
      jump *= 2;
    }
    int bStart = start, bEnd = end;
    while (bStart <= bEnd) {
      int middle = (bStart + bEnd) / 2;
      int elem = reader->get(middle);
      if (elem == key) {
        return middle;
      } else if (elem < key) {
        bStart = middle + 1;
      } else {
        bEnd = middle - 1;
      }
    }
    if (reader->get(bStart) != key) {
      return -1;
    }
    return bStart;
  }
};

int main(int argc, char *argv[]) {
  ArrayReader *reader = new ArrayReader(
      vector<int>{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << SearchInfiniteSortedArray::search(reader, 16) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 11) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 4) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 30) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 29) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 35) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 2) << endl;
  return 0;
}
