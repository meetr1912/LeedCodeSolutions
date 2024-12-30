class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentMax = 0;
        int farthestJump = 0;
        
        // We don't need to check the last element since we're already there
        for (int i = 0; i < nums.size() - 1; i++) {
            farthestJump = max(farthestJump, i + nums[i]);
            
            if (i == currentMax) {
                jumps++;
                currentMax = farthestJump;
            }
        }
        
        return jumps;
    }
};