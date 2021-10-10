using namespace std;

#include <iostream>
#include <queue>

// PROBLEM: Given a binary tree, connect each node with its level order successor. The last node of each level should 
// point to a null node.

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;

  TreeNode(int x) {
    val = x;
    left = right = next = nullptr;
  }

  // level order traversal using 'next' pointer
  virtual void printLevelOrder() {
    TreeNode *nextLevelRoot = this;
    while (nextLevelRoot != nullptr) {
      TreeNode *current = nextLevelRoot;
      nextLevelRoot = nullptr;
      while (current != nullptr) {
        cout << current->val << " ";
        if (nextLevelRoot == nullptr) {
          if (current->left != nullptr) {
            nextLevelRoot = current->left;
          } else if (current->right != nullptr) {
            nextLevelRoot = current->right;
          }
        }
        current = current->next;
      }
      cout << endl;
    }
  }
};

class ConnectLevelOrderSiblings {
 public:
  static void connect(TreeNode *root) {
    if (root == NULL)
      return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int sz = q.size();

      for (int i=0; i < sz; i++) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);

        if (i == sz - 1) {
          node->next = NULL;
        } else {
          node->next = q.front();
        }
      }
    }
  }

  // Time: O(N) process N nodes in tree
  // Space: O(N) worst case n/2 nodes in queue
};