using namespace std;

#include <iostream>
#include <queue>
#include <algorithm>

// PROBELM: Given a binary tree, populate an array to represent the averages of all of its levels.

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

class LevelAverage {
 public:
  static vector<double> findLevelAverages(TreeNode *root) {
    if (root == NULL)
      return {};

    vector<double> result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int sz = q.size();

      double sum = 0;
      for (int i=0; i < sz; i++) {
        TreeNode* node = q.front();
        q.pop();
        sum += node->val;

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      
      double avg = sum / sz;
      result.push_back(avg);
    }

    return result;
  }

  // Time: O(n) to process all nodes in tree
  // Space: O(n) since queue can contain n/2 elements in worst case
};