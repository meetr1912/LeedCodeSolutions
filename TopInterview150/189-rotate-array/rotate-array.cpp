class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle cases where k > n
        
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        // Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        // Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};