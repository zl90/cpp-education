using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {
    std::sort(arr.begin(), arr.end());

    int closest_sum = arr[0] + arr[1] + arr[2];

    for (int a = 0; a < arr.size() - 2; a++) {
      if (a > 0 && arr[a] == arr[a - 1]) {
        continue;  // skip duplicate triplets
      }

      int b = a + 1, c = arr.size() - 1, prev_b = b, prev_c = c;
      while (b < c) {
        int sum = arr[a] + arr[b] + arr[c];
        if (sum == targetSum) return sum;
        int curr_dist = abs(targetSum - sum);
        int closest_dist = abs(targetSum - closest_sum);
        bool is_closer = curr_dist < closest_dist ||
                         (curr_dist == closest_dist && sum < closest_sum);
        if (is_closer) {
          closest_sum = sum;
        }
        bool is_below = targetSum - sum > 0;
        if (is_below) {
          while (arr[b] == arr[prev_b]) {
            b++;  // skip duplicate triplets
          }
          prev_b = b;
        } else {
          while (arr[c] == arr[prev_c]) {
            c--;  // skip duplicate triplets
          }
          prev_c = c;
        }
      }
    }

    return closest_sum;
  }
};

int main() {
  vector<int> test{-3, -1, 1, 2};
  int test_target = 0;

  auto results = TripletSumCloseToTarget::searchTriplet(test, test_target);

  std::cout << results << "\n";
}
