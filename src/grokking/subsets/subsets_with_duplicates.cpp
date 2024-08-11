using namespace std;

#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

class SubsetWithDuplicates {
 public:
  static vector<vector<int>> findSubsets(vector<int> &nums) {
    if (nums.size() == 0) {
      return {};
    }
    vector<vector<int>> subsets;
    sort(nums.begin(), nums.end());
    subsets.push_back({});
    int start = 0, end = subsets.size();
    for (int a = 0; a < nums.size(); a++) {
      vector<vector<int>> temp = subsets;
      if (a > 0 && nums[a - 1] == nums[a]) {
        for (int i = start; i < end; i++) {
          temp[i].push_back(nums[a]);
          subsets.push_back(temp[i]);
        }
      } else {
        for (int i = 0; i < end; i++) {
          temp[i].push_back(nums[a]);
          subsets.push_back(temp[i]);
        }
      }
      start = end;
      end = subsets.size();
    }
    return subsets;
  }

 private:
  static int getDuplicateCount(int k) {
    int count = 0;
    for (int i = 1; i < k; i++) {
      count += pow(2, i);
    }
    return count;
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
