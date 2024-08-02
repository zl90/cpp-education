using namespace std;

#include <deque>
#include <iostream>
#include <queue>
#include <vector>

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

class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> result;
    bool zigging = true;
    deque<TreeNode*> q;
    q.push_back(root);
    while (!q.empty()) {
      vector<int> currLevel;
      int levelSize = q.size();
      while (levelSize-- > 0) {  // Not very readable. Just do a for loop.
        if (zigging) {
          TreeNode* currNode = q.front();
          q.pop_front();
          if (currNode->left) q.push_back(currNode->left);
          if (currNode->right) q.push_back(currNode->right);
          currLevel.push_back(currNode->val);
        } else {
          TreeNode* currNode = q.back();
          q.pop_back();
          if (currNode->right) q.push_front(currNode->right);
          if (currNode->left) q.push_front(currNode->left);
          currLevel.push_back(currNode->val);
        }
      }
      result.push_back(currLevel);
      zigging = !zigging;
    }

    return result;
  }
};

int main(int argc, char* argv[]) {
  TreeNode* root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);

  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
  }
  cout << endl;
}
