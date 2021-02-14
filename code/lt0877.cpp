// https://leetcode-cn.com/problems/stone-game/
// stone game
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        size_t size = piles.size();
        vector<vector<int>> dp = {size, vector<int>(size, 0)};
        vector<int> sum(size + 1, 0);

        for(int i = 0; i < size; i++){
            dp[i][i] = piles[i];
            sum[i + 1] = piles[i] + sum[i];
        }

        for(int l = 2; l <= size; l++){
            for(int i = 0; i < size - l + 1; i++){
                int j = i + l - 1;
                dp[i][j] = dp[i][i] + (sum[j + 1] - sum[i + 1] - dp[i + 1][j]);
                dp[i][j] = max(dp[i][j], dp[j][j] + (sum[j] - sum[i] - dp[i][j - 1]));
            }
        }

        return dp[0][size - 1]> (sum[size] - sum[0]) / 2;
    }
};