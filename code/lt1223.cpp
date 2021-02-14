// https://leetcode-cn.com/problems/dice-roll-simulation/
// dice roll simulation
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(6 + 1, vector<int>(16, 0)));

        const int MOD = pow(10, 9) + 7;

        for(int i = 1; i <= 6; i++)
            dp[0][i][1] = 1;
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= 6; j++){
                
                for(int k = 2; k <= rollMax[j - 1]; k++){
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }

                for(int pj = 1; pj <= 6; pj++){
                    if(pj == j)
                        continue;
                    for(int u = 1; u <= rollMax[pj - 1]; u++){
                        dp[i][j][1] = (dp[i][j][1] + dp[i - 1][pj][u]) % MOD;
                    }
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= 6; i++){
            for(int j = 1; j <= rollMax[i - 1]; j++){
                ans = (ans + dp[n - 1][i][j]) % MOD;
            }
        }

        return ans;
    }
};