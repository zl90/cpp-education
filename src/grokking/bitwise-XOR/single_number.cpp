using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
 public:
  static int findSingleNumber(const vector<int>& arr) {
    int xorSum = 0;
    for (const auto& element : arr) {
      xorSum ^= element;
    }
    return xorSum;
  }
};

int main(int argc, char* argv[]) {
  cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3})
       << endl;
  cout << SingleNumber::findSingleNumber(vector<int>{7, 9, 7}) << endl;
}
