using namespace std;

#include <iostream>

// PROBLEM: Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf such that 
// the sum of all the node values of that path equals ‘S’.

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

class TreePathSum {
 public:
  static bool hasPath(TreeNode *root, int sum) {
    if (root == NULL)
      return false;

    if (root->left == NULL && root->right == NULL && sum - root->val == 0)
      return true;

    return hasPath(root->left, sum - root->val) 
      || hasPath(root->right, sum - root->val);
  }

  // Time: O(N) process all nodes in tree
  // Space: O(N) worst case have a skewed tree
};