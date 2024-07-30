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

class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      // remove levelSize elements from the queue, pushing their children as we
      // go
      int levelSize = q.size();
      vector<int> currentLevel;
      while (levelSize-- > 0) {
        TreeNode *currentNode = q.front();
        currentLevel.push_back(currentNode->val);
        q.pop();
        if (currentNode->left) q.push(currentNode->left);
        if (currentNode->right) q.push(currentNode->right);
      }
      result.push_back(currentLevel);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);

  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
