// https://leetcode-cn.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
// number of ways to wear different hats to each other
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        size_t n = hats.size();
        vector<set<int>> record = {41, set<int>()};
        const int MOD = pow(10, 9) + 7; 
        vector<int> dp(1 << n);

        for(int i = 0; i < n; i++){
            for(int hat : hats[i])
                record[hat].insert(i);
        }

        dp[0] = 1;

        for(int i = 1; i <= 40; i++){
            for(int state = (1 << n) - 1;state >= 0; state--){
                for(int person : record[i]){
                    if(state & (1 << person)){
                        continue;
                    }

                    int next = state | (1 << person);
                    dp[next] = (dp[next] + dp[state]) % MOD;
                }
            }
        }

        return dp[(1 << n) - 1];

    }
};