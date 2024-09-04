using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Permutations {
 public:
  static vector<vector<int>> findPermutations(const vector<int>& nums) {
    if (nums.size() <= 1) return {nums};
    vector<vector<int>> result;
    queue<vector<int>> subPermutations;
    subPermutations.push({});
    for (const auto& num : nums) {
      int levelSize = subPermutations.size();
      for (int i = 0; i < levelSize; i++) {
        vector<int> currSubPermutation = subPermutations.front();
        subPermutations.pop();
        vector<vector<int>> children =
            insertIntoAllPlaces(num, currSubPermutation);
        for (const auto& child : children) {
          if (child.size() == nums.size()) {
            result.push_back(child);
          } else {
            subPermutations.push(child);
          }
        }
      }
    }
    return result;
  }

 private:
  static vector<vector<int>> insertIntoAllPlaces(int x, vector<int> nums) {
    vector<vector<int>> output;
    for (int i = 0; i < nums.size() + 1; i++) {
      vector<int> permutation = nums;
      permutation.insert(permutation.begin() + i, x);
      output.push_back(permutation);
    }
    return output;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result =
      Permutations::findPermutations(vector<int>{1, 3, 5});
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
