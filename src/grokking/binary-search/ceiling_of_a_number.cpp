using namespace std;

#include <iostream>
#include <vector>

class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    if (arr[arr.size() - 1] > key) return -1;
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int i = (start + end) / 2;
      if (arr[i] == key) {
        return i;
      } else if (arr[i] > key) {
        end = i - 1;
      } else {
        start = i + 1;
      }
    }
    return start;
  }
};

int main(int argc, char* argv[]) {
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 6}, 6)
       << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15},
                                                   12)
       << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17)
       << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1)
       << endl;
}
