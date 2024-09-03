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
    int count = 0;
    dfs(root, S, {}, count);
    return count;
  }

 private:
  static void dfs(TreeNode *root, int S, vector<int> currPath, int &count) {
    if (!root) return;
    currPath.push_back(root->val);
    if (hasValidPath(currPath, S)) {
      count++;
    }
    dfs(root->left, S, currPath, count);
    dfs(root->right, S, currPath, count);
  }

  static bool hasValidPath(const vector<int> &currPath, int S) {
    int sum = 0;
    for (int i = currPath.size() - 1; i >= 0; i--) {
      sum += currPath[i];
      if (sum == S) return true;
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
