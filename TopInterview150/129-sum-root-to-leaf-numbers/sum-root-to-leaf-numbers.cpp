class Solution {
public:
    int dfs(TreeNode* root, int currentSum) {
        if (!root) return 0;
        
        currentSum = currentSum * 10 + root->val;
        
        // If leaf node, return current path sum
        if (!root->left && !root->right) {
            return currentSum;
        }
        
        // Recurse on both subtrees and return their sum
        return dfs(root->left, currentSum) + dfs(root->right, currentSum);
    }
    
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};