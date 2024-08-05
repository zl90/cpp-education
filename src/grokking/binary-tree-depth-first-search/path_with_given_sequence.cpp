#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class PathWithGivenSequence {
 public:
  static bool findPath(TreeNode *root, const vector<int> &sequence) {
    if (!root && sequence.size() == 0) return true;
    if (!root) return false;

    return dfs(root, {}, sequence);
  }

 private:
  static bool dfs(TreeNode *root, vector<int> currentPath,
                  vector<int> sequence) {
    if (!root) return false;
    currentPath.push_back(root->val);
    if (!root->left && !root->right) {
      return comparePaths(currentPath, sequence);
    } else {
      return dfs(root->left, currentPath, sequence) ||
             dfs(root->right, currentPath, sequence);
    }
  }

  static bool comparePaths(vector<int> currentPath, vector<int> sequence) {
    if (currentPath.size() != sequence.size()) return false;
    for (int i = 0; i < currentPath.size(); i++) {
      if (currentPath[i] != sequence[i]) return false;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Tree has path sequence: "
       << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 7}) << endl;
  cout << "Tree has path sequence: "
       << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6}) << endl;
}
