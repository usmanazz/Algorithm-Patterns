using namespace std;

#include <iostream>
#include <queue>

// PROBLEM: Find the minimum depth of a binary tree. The minimum depth is the number of nodes along the shortest path 
// from the root node to the nearest leaf node.

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

    if (root == NULL)
      return minimumTreeDepth;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int sz = q.size();
      minimumTreeDepth++;
      
      for (int i=0; i < sz; i++) {
        TreeNode* node = q.front();
        q.pop();

        if (!node->left && !node->right) return minimumTreeDepth;

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }

    return minimumTreeDepth;
  }

  // Time: O(N) to process roughly n nodes in tree
  // Space: O(N) roughly n/2 nodes in queue
};