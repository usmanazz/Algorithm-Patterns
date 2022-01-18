class Solution {
    int ans;
public:
    int distributeCoins(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        ans = 0;
        dfs(root);
        return ans;
    }
    
private:
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        ans += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
    
    // Time: O(N) n number of nodes in tree
    // Space: O(H) h is height of tree
};