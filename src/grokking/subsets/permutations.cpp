using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Permutations {
 public:
  static vector<vector<int>> findPermutations(const vector<int> &nums) {
    vector<vector<int>> result;
    queue<vector<int>> q;
    q.push({});
    for (const auto &num : nums) {
      int n = q.size();
      vector<vector<int>> newSubPermutations;
      for (int i = 0; i < n; i++) {
        vector<int> curr = q.front();
        q.pop();
        insertInAllPlaces(num, newSubPermutations, curr);
      }

      for (const auto &subPermutation : newSubPermutations) {
        if (subPermutation.size() == nums.size()) {
          result.push_back(subPermutation);
        } else {
          q.push(subPermutation);
        }
      }
    }
    return result;
  }

 private:
  static void insertInAllPlaces(int num, vector<vector<int>> &results,
                                vector<int> curr) {
    for (int i = 0; i < curr.size() + 1; i++) {
      vector<int> output = curr;
      output.insert(output.begin() + i, num);
      results.push_back(output);
    }
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
