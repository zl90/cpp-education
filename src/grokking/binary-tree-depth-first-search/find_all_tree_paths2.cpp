using namespace std;

#include <iostream>
#include <stack>
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

class FindAllTreePaths {
 public:
  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    dfs(root, sum, {}, allPaths);
    return allPaths;
  }

 private:
  static void dfs(TreeNode *root, int S, vector<int> currPath,
                  vector<vector<int>> &allPaths) {
    if (!root) return;
    currPath.push_back(root->val);
    if (!root->left && !root->right && root->val == S) {
      allPaths.push_back(currPath);
    }
    dfs(root->left, S - root->val, currPath, allPaths);
    dfs(root->right, S - root->val, currPath, allPaths);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);

  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
