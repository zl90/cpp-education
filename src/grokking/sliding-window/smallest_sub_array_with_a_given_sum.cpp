using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int> &arr) {
    int smallest_size = arr.size(), sum = 0, a = 0, b = 0, prev_b = -1;
    bool has_found_subarray = false;

    while (b < arr.size()) {
      if (b != prev_b) {
        sum += arr[b];
      }
      prev_b = b;
      if (sum >= S) {
        smallest_size = min(smallest_size, b - a + 1);
        sum -= arr[a];
        a++;
        has_found_subarray = true;
      } else {
        b++;
      }
    }

    if (has_found_subarray) {
      return smallest_size;
    }

    return 0;
  }
};

int main() {
  vector<int> arr{2, 1, 5, 2, 3, 2};
  int s = 7;

  int result = MinSizeSubArraySum::findMinSubArray(s, arr);

  std::cout << result << "\n";

  arr = {2, 1, 5, 2, 8};
  s = 7;

  result = MinSizeSubArraySum::findMinSubArray(s, arr);

  std::cout << result << "\n";

  arr = {3, 4, 1, 1, 6};
  s = 8;

  result = MinSizeSubArraySum::findMinSubArray(s, arr);

  std::cout << result << "\n";
}