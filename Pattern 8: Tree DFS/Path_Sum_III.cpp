class Solution {
    int count;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;
        
        count = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        preorder(root, targetSum, 0, umap);
        return count;
    }
    
private:
    void preorder(TreeNode* root, int targetSum, int curSum, 
                  unordered_map<int, int> umap) {
        if (root == NULL)
            return;
        
        curSum += root->val;
        
        int diff = curSum - targetSum;
        count += umap.find(diff) != umap.end() ? umap[diff] : 0;
        
        if (umap.find(curSum) == umap.end())
            umap[curSum] = 0;
        umap[curSum]++;
        
        preorder(root->left, targetSum, curSum, umap);
        preorder(root->right, targetSum, curSum, umap);
    }
    
    // Time : O(n) to iterate thru each node once
    // Space: O(n) to keep hashmap which contains n elements worst case
};