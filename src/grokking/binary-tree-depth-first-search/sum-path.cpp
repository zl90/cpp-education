using namespace std;

#include <iostream>

class TreeNode {
 public:
  int val = 0;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class TreePathSum {
 public:
  static bool hasPath(TreeNode* root, int sum) {
    if (!root) return false;
    if (root->val == sum && !root->left && !root->right) {
      return true;
    } else {
      return hasPath(root->left, sum - root->val) ||
             hasPath(root->right, sum - root->val);
    }
  }
};

int main(int argc, char* argv[]) {
  TreeNode* root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);

  cout << "Tree has path: " << TreePathSum::hasPath(root, 23) << endl;
  cout << "Tree has path: " << TreePathSum::hasPath(root, 16) << endl;
}
