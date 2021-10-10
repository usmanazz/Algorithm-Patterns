using namespace std;

#include <iostream>
#include <queue>
#include <vector>

// PROBLEM: Given a binary tree, populate an array to represent its zigzag level order traversal. 
// You should populate the values of all nodes of the first level from left to right, then right to left for 
// the next level and keep alternating in the same manner for the following levels.

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

class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    if (root == NULL)
      return {};

    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    int isLeftToRight = true;

    while(!q.empty()) {
      int sz = q.size();

      vector<int> subarr(sz, 0);
      for (int i=0; i < sz; i++) {
        TreeNode* node = q.front();
        q.pop();

        if (isLeftToRight) {
          subarr[i] = node->val;
        } else {
          subarr[sz - i - 1] = node->val;
        }

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }

      result.push_back(subarr);
      isLeftToRight = !isLeftToRight;
    }

    return result;
  }

  // Time: O(N) to process N nodes in tree
  // Space: O(N) to create level order list and queue contains N/2 elements worst case
};