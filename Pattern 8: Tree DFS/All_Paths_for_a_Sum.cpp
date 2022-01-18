using namespace std;

#include <iostream>
#include <vector>

// PROBLEM: Given a binary tree and a number ‘S’, find all paths from root-to-leaf such that the sum of all 
// the node values of each path equals ‘S’.

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

class FindAllTreePaths {
 public:
  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    dfs(root, sum, allPaths, {});
    return allPaths;
  }

 private:
  static void dfs(TreeNode* root, int sum, vector<vector<int>>& ans, vector<int> path) {
    if (root == NULL)
      return;
      
    path.push_back(root->val);

    if (root->left == NULL && root->right == NULL && (sum - root->val == 0)) {
      ans.push_back(path);
      return;
    }

    dfs(root->left, sum - root->val, ans, path);
    dfs(root->right, sum - root->val, ans, path);
  }

  // Time: O(n logn) can have a path for every root-to-leaf node and will need to copy over path
  //       to the result array which is in total O(N*logn)
  
  // Space: O(n logn) if we take output list into consideration, we have N paths and each path can
  //        up to logN nodes for (almost )complete binary tree.
};