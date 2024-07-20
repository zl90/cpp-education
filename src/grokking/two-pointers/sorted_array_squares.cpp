using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares;

    int right = 0, left = n - 1;
    // find smallest positive number
    while (arr[right] < 0) {
      right++;
    }
    // find largest negative number
    while (arr[left] >= 0) {
      left--;
    }
    // Build the output array
    while (left >= 0 || right < n) {
      if (left < 0) {
        squares.push_back(arr[right] * arr[right]);
        right++;
      } else if (right >= n) {
        squares.push_back(arr[left] * arr[left]);
        left--;

      } else {
        bool is_left_smallest = std::abs(arr[left] * arr[left]) <=
                                std::abs(arr[right] * arr[right]);
        if (is_left_smallest) {
          squares.push_back(arr[left] * arr[left]);
          left--;
        } else {
          squares.push_back(arr[right] * arr[right]);
          right++;
        }
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
