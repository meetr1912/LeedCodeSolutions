class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = words[0].length();
        int n = target.length();
        
        // Count frequency of characters at each position
        vector<vector<long long>> freq(m, vector<long long>(26, 0));
        for (int i = 0; i < m; i++) {
            for (const string& word : words) {
                freq[i][word[i] - 'a']++;
            }
        }
        
        // dp[i][j] represents ways to form target[0...i] using first j positions
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        dp[0][0] = 1;
        
        // Fill dp table
        for (int j = 0; j < m; j++) {
            dp[0][j + 1] = 1;
            for (int i = 0; i < n; i++) {
                dp[i + 1][j + 1] = dp[i + 1][j];
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + 
                    (dp[i][j] * freq[j][target[i] - 'a']) % MOD) % MOD;
            }
        }
        
        return dp[n][m];
    }
};