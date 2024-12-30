class Solution {
private:
    int maxSum = INT_MIN;
    
    int maxGain(TreeNode* root) {
        if (!root) return 0;
        
        // Get max gain from left and right subtrees
        int leftGain = max(maxGain(root->left), 0);
        int rightGain = max(maxGain(root->right), 0);
        
        // Calculate current path sum
        int currentPathSum = root->val + leftGain + rightGain;
        
        // Update global maximum
        maxSum = max(maxSum, currentPathSum);
        
        // Return maximum single path including current node
        return root->val + max(leftGain, rightGain);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};