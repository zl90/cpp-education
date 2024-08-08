using namespace std;

#include <iostream>
#include <vector>

class Subsets {
 public:
  static vector<vector<int>> findSubsets(const vector<int> &nums) {
    vector<vector<int>> subsets{{}};
    for (int i = 0; i < nums.size(); i++) {
      vector<vector<int>> temp = subsets;
      for (auto &element : temp) {
        element.push_back(nums[i]);
        subsets.push_back(element);
      }
    }
    return subsets;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = Subsets::findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
