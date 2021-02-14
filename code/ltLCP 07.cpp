// https://leetcode-cn.com/problems/chuan-di-xin-xi/
// chuan di xin xi
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> dp = {static_cast<size_t>(n), vector<int>(k + 1, 0)};
        vector<vector<int>> froms = {static_cast<size_t>(n), vector<int>()};

        size_t size = relation.size();

        for(int i = 0; i < size; i++){
            froms[relation[i][1]].push_back(relation[i][0]);
        }

        dp[0][0] = 1;

        for(int i = 1; i <= k; i++){
            for(int j = 0; j < n; j++){
                int num = froms[j].size();
                for(int k = 0; k < num; k++){
                    dp[j][i] = dp[j][i] + dp[froms[j][k]][i - 1];
                }
            }
        }

        return dp[n - 1][k];
    }
};