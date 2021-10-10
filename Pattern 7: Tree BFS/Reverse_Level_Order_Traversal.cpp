using namespace std;

#include <deque>
#include <iostream>
#include <queue>
#include <vector>

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

// PROBLEM: Given a binary tree, populate an array to represent its level-by-level traversal in reverse order, i.e., 
// the lowest level comes first. You should populate the values of all nodes in each level from left to right in separate sub-arrays.

class ReverseLevelOrderTraversal {
 public:
  static deque<vector<int>> traverse(TreeNode *root) {
    deque<vector<int>> result = deque<vector<int>>();

    if (root == NULL)
      return result;

    queue<TreeNode*> q;
    q.push(root);

    // q:
    // subarr:
    // result:  [4 5 6 7] [2 3] [1] 

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
      result.push_front(subarr);
    }

    return result;
  }

  // Time: O(N) to process all nodes in tree
  // Space: O(N) queue contains at most N/2 nodes and return level order traversal list
};