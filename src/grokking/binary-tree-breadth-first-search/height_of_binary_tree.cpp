using namespace std;

#include <iostream>
#include <queue>

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

class MaximumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    int maximumTreeDepth = 0;
    if (!root) return maximumTreeDepth;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int levelSize = q.size();
      maximumTreeDepth++;
      while (levelSize-- > 0) {
        TreeNode *currNode = q.front();
        q.pop();
        if (currNode->left) q.push(currNode->left);
        if (currNode->right) q.push(currNode->right);
      }
    }
    return maximumTreeDepth;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->right->right->right = new TreeNode(8);
  cout << "Tree Maximum Depth: " << MaximumBinaryTreeDepth::findDepth(root)
       << endl;  // 4
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  root->right->left->left->right = new TreeNode(13);
  cout << "Tree Maximum Depth: " << MaximumBinaryTreeDepth::findDepth(root)
       << endl;  // 5
}
