// https://leetcode-cn.com/problems/stone-game-vii/
// stone game vii
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        size_t n = stones.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> sums(n + 1, 0);
        
        for(int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + stones[i];
        
        for(int len = 2; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                int j = i + len - 1;
                dp[i][j] = max(dp[i][j], sums[j + 1] - sums[i + 1] - dp[i + 1][j]);
                dp[i][j] = max(dp[i][j], sums[j] - sums[i] - dp[i][j - 1]);
                
            }
        }
        
        return dp[0][n - 1];
    }
};