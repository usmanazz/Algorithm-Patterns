using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given a binary tree where each node can only have a digit (0-9) value, each root-to-leaf path 
// will represent a number. Find the total sum of all the numbers represented by all paths.

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

class SumOfPathNumbers {
 public:
  static int findSumOfPathNumbers(TreeNode *root) {
    int totalPathsSum = 0;
    dfs(root, totalPathsSum, 0);
    return totalPathsSum;
  }

 private:
  static void dfs(TreeNode* root, int& totalPathsSum, int path) {
    if (root == NULL)
      return;

    path = path * 10 + root->val;
    
    if (root->left == NULL && root->right == NULL) {
      totalPathsSum += path;
      return;
    }

    dfs(root->left, totalPathsSum, path);
    dfs(root->right, totalPathsSum, path);
  }

  // Time: O(n) visit every single node once
  // Space: O(n) call stack contains n nodes when height == number of nodes in tree
};