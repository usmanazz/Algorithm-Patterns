using namespace std;

#include <iostream>
#include <queue>

// PROBLEM: Given a binary tree and a node, find the level order successor of the given node in the tree. 
// The level order successor is the node that appears right after the given node in the level order traversal.


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
    if (root == NULL)
      return NULL;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int sz = q.size();

      for (int i=0; i < sz; i++) {
        TreeNode* node = q.front();
        q.pop();

        // add child nodes first to make sure we always get a successor if it exists
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);

        // found given node so return successor if it exists
        if (node->val == key) {
          if (q.empty())
            return NULL;
          else
            return q.front();
        }
      }
    }

   return nullptr;
  }

  // Time: O(n) to process all nodes in tree
  // Space: O(n) worst case n/2 nodes in queue
};