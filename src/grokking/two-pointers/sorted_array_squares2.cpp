using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    vector<int> squares(arr.size());
    int index = arr.size() - 1, a = 0, b = arr.size() - 1;
    while (a < b) {
      int num1 = arr[a] * arr[a];
      int num2 = arr[b] * arr[b];
      if (num1 > num2) {
        squares[index--] = num1;
        a++;
      } else {
        squares[index--] = num2;
        b--;
      }
    }
    return squares;
  }
};

int main() {
  vector<int> test{-2, -1, 0, 2, 3};

  vector<int> results = SortedArraySquares::makeSquares(test);

  for (const auto& element : results) {
    std::cout << element << ", ";
  }

  std::cout << "\n";
}
