using namespace std;

#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

class SubsetWithDuplicates {
 public:
  static vector<vector<int>> findSubsets(vector<int> &nums) {
    if (nums.size() == 0) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> subsets;
    subsets.push_back({});
    subsets.push_back({nums[0]});
    vector<vector<int>> prevNewSubsets = subsets;
    for (int i = 1; i < nums.size(); i++) {
      vector<vector<int>> copy;
      if (nums[i] == nums[i - 1]) {
        copy = prevNewSubsets;
      } else {
        copy = subsets;
      }
      prevNewSubsets = {};
      for (auto &subset : copy) {
        subset.push_back(nums[i]);
        subsets.push_back(subset);
        prevNewSubsets.push_back(subset);
      }
    }
    return subsets;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {1, 3, 3};
  vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vec = {1, 5, 3, 3};
  result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
