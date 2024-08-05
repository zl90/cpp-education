using namespace std;

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

class CountAllPathSum {
 public:
  static int countPaths(TreeNode *root, int S) {
    if (!root && S == 0) return true;
    if (!root) return false;
    int result = 0;
    dfs(root, {}, result, S);
    return result;
  }

 private:
  static void dfs(TreeNode *root, vector<int> currentPath, int &result, int S) {
    if (!root) return;
    currentPath.push_back(root->val);
    if (hasPath(currentPath, S)) result++;
    dfs(root->left, currentPath, result, S);
    dfs(root->right, currentPath, result, S);
  }

  static bool hasPath(vector<int> currentPath, int S) {
    for (int i = currentPath.size() - 1; i >= 0; i--) {
      S -= currentPath[i];
      if (S == 0) return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);

  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}
