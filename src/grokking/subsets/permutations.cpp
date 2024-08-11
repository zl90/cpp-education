using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Permutations {
 public:
  static vector<vector<int>> findPermutations(const vector<int> &nums) {
    if (nums.size() == 0) return {};
    vector<vector<int>> result;
    queue<vector<int>> q;
    q.push({});
    for (int a = 0; a < nums.size(); a++) {
      int levelSize = q.size();
      for (int i = 0; i < levelSize; i++) {
        vector<int> curr = q.front();
        q.pop();
        vector<vector<int>> newSubPermutations =
            insertIntoAllPlaces(nums[a], curr);
        for (const auto &subPermutation : newSubPermutations) {
          if (a == nums.size() - 1) {
            result.push_back(subPermutation);
          } else {
            q.push(subPermutation);
          }
        }
      }
    }
    return result;
  }

 private:
  static vector<vector<int>> insertIntoAllPlaces(int num, vector<int> curr) {
    vector<vector<int>> permutations;
    for (int i = 0; i < curr.size() + 1; i++) {
      vector<int> output = curr;
      output.insert(output.begin() + i, num);
      permutations.push_back(output);
    }
    return permutations;
  }
};

int main(int argc, char *argv[]) {
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
