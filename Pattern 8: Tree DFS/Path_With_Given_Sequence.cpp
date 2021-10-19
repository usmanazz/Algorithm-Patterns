#include <iostream>
#include <vector>

using namespace std;

// PROBLEM: Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class PathWithGivenSequence {
 public:
  static bool findPath(TreeNode *root, const vector<int> &sequence) {
    if (root == NULL)
      return sequence.empty();

    return dfs(root, sequence, 0);
  }

 private:
  static bool dfs(TreeNode* root, const vector<int>& sequence, int idx) {
    if (root == NULL)
      return false;
    if (idx >= sequence.size() || sequence[idx] != root->val)
      return false;
    
    // found a path equal to sequence
    if (idx == sequence.size() - 1 && 
      root->left == NULL && root->right == NULL)
      return true;
    
    // sequence equal to curr path so far but path has not ended
    if (sequence[idx] == root->val && idx == sequence.size() - 1 && (root->left || root->right))
      return false;

    return dfs(root->left, sequence, idx + 1) || dfs(root->right, sequence, idx + 1);
  }

  // Time: O(N) to process all nodes
  // Space: O(N) where height == number of nodes in tree
};