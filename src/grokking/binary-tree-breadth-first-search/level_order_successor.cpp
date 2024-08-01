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

class LevelOrderSuccessor {
 public:
  static TreeNode *findSuccessor(TreeNode *root, int key) {
    bool hasFoundGivenNode = false;
    if (!root) return nullptr;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int levelSize = q.size();
      while (levelSize-- > 0) {
        TreeNode *currNode = q.front();
        if (hasFoundGivenNode) return currNode;
        q.pop();
        if (currNode->val == key) hasFoundGivenNode = true;
        if (currNode->left) q.push(currNode->left);
        if (currNode->right) q.push(currNode->right);
      }
    }
    return nullptr;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);

  TreeNode *result = LevelOrderSuccessor::findSuccessor(root, 12);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }

  result = LevelOrderSuccessor::findSuccessor(root, 9);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }

  return 0;
}
