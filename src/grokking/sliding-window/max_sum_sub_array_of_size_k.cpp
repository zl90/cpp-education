using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0, sum = 0, a = 0;
    for (int b = 0; b < arr.size(); b++) {
      sum += arr[b];
      if (b > k - 1) {
        sum -= arr[a];
        a++;
      }
      maxSum = max(maxSum, sum);
    }
    return maxSum;
  }
};

int main() {
  vector<int> arr{2, 1, 5, 1, 3, 2};
  int k = 3;

  int result = MaxSumSubArrayOfSizeK::findMaxSumSubArray(k, arr);

  std::cout << result << "\n";

  arr = {2, 3, 4, 1, 5};
  k = 2;

  result = MaxSumSubArrayOfSizeK::findMaxSumSubArray(k, arr);

  std::cout << result << "\n";
}
