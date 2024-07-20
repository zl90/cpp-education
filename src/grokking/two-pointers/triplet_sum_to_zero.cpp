using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(const vector<int>& arr) {
    vector<vector<int>> triplets;

    auto arr_sorted = arr;
    std::sort(arr_sorted.begin(), arr_sorted.end());

    for (int a = 0; a < arr_sorted.size() - 2; a++) {
      if (a > 0 && arr_sorted[a] == arr_sorted[a - 1]) {
        continue;  // skip duplicate triplets
      }

      int b = a + 1, c = arr_sorted.size() - 1;
      int previous_b = b, previous_c = c;
      while (b < c) {
        int sum = arr_sorted[a] + arr_sorted[b] + arr_sorted[c];
        if (sum == 0) {
          triplets.push_back({arr_sorted[a], arr_sorted[b], arr_sorted[c]});
          while (arr_sorted[b] == arr_sorted[previous_b]) {
            b++;  // skip duplicate triplets
          }
          previous_b = b;
        } else if (sum < 0) {
          while (arr_sorted[b] == arr_sorted[previous_b]) {
            b++;  // skip duplicate triplets
          }
          previous_b = b;
        } else {
          while (arr_sorted[c] == arr_sorted[previous_c]) {
            c--;  // skip duplicate triplets
          }
          previous_c = c;
        }
      }
    }

    return triplets;
  }
};

int main() {
  vector<int> test{-3, 0, 1, 2, -1, 1, -2};

  auto results = TripletSumToZero::searchTriplets(test);

  for (const auto& triplet : results) {
    for (const auto& element : triplet) {
      std::cout << element << ", ";
    }
    std::cout << "\n";
  }

  std::cout << "\n";
}
