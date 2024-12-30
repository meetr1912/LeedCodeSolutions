class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long> dp(high + 1, 0);
        const int MOD = 1e9 + 7;
        dp[0] = 1;
        
        for (int i = 1; i <= high; i++) {
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            }
            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }
        }
        
        long result = 0;
        for (int i = low; i <= high; i++) {
            result = (result + dp[i]) % MOD;
        }
        
        return result;
    }
};