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

class MinimumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    int minimumTreeDepth = 0;
    if (!root) return minimumTreeDepth;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      minimumTreeDepth++;
      int levelSize = q.size();
      while (levelSize-- > 0) {
        TreeNode *currNode = q.front();
        q.pop();
        if (!currNode->left && !currNode->right) return minimumTreeDepth;
        if (currNode->left) q.push(currNode->left);
        if (currNode->right) q.push(currNode->right);
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root)
       << endl;
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root)
       << endl;
}
