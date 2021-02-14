// https://leetcode-cn.com/problems/profitable-schemes/
// profitable schemes
class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        size_t total = accumulate(profit.begin(), profit.end(), 0);
        vector<vector<int>> dp = {static_cast<size_t>(G + 1), vector<int>(P + 1, 0)};
        dp[0][0] = 1;

        size_t size = group.size();

        const int MOD = pow(10, 9) + 7;

        for(int i = 0; i < size; i++){
            for(int g = G; g >= group[i]; g--){
                for(int p = P; p >= max(0, P - profit[i]); p--){
                    dp[g][P] = (dp[g][P] + dp[g - group[i]][p]) % MOD; 
                }
                
                for(int p = P - 1; p >= profit[i]; p--){
                    dp[g][p] = (dp[g][p] + dp[g - group[i]][p - profit[i]]) % MOD; 
                }
                
            }
        }

        int res = 0;

        for(int g = 0; g <= G; g++){
            res = (res + dp[g][P]) % MOD;
        }
        return res;
    }
};