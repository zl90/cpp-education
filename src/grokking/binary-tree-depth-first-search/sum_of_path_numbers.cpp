using namespace std;

#include <cmath>
#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class SumOfPathNumbers {
 public:
  static int findSumOfPathNumbers(TreeNode *root) {
    int totalPathsSum = 0;
    vector<int> allPaths;
    dfs(root, 0, allPaths);
    for (const auto &number : allPaths) {
      totalPathsSum += number;
    }
    return totalPathsSum;
  }

 private:
  static void dfs(TreeNode *root, int num, vector<int> &allPaths) {
    if (!root) return;
    if (!root->left && !root->right) {
      // leaf node found
      allPaths.push_back(num * 10 + root->val);
    }
    dfs(root->left, num * 10 + root->val, allPaths);
    dfs(root->right, num * 10 + root->val, allPaths);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Total Sum of Path Numbers: "
       << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}
