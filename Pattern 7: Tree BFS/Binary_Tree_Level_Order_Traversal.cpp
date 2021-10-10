using namespace std;

#include <iostream>
#include <queue>
#include <vector>

// PROBLEM: Given a binary tree, populate an array to represent its level-by-level traversal. 
// You should populate the values of all nodes of each level from left to right in separate sub-arrays.

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
    if (root == NULL)
      return {};
    
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int sz = q.size();

      vector<int> subarr;
      for (int i=0; i < sz; i++) {
        TreeNode* node = q.front(); 
        q.pop();
        subarr.push_back(node->val);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      
      result.push_back(subarr);
    }

    return result;
  }

  // Time: O(N) where n is number of nodes in tree
  // Space: O(W) queue will contain max tree width number of nodes
};