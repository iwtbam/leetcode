#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        
        k = min(k, n);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
        
        const static int MOD = pow(10, 9) + 7;
        
        for(int i = 1; i <= m; i++)
            dp[0][i][1] = 1;
    
        
        
        int res = 0;

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= m; j++){
                for(int pj = 1; pj<=m; pj++){
                    for(int c = 1; c <= k; c++){
                        if(j > pj){
                            if(c < k)
                                dp[i][j][c+1] = (dp[i][j][c + 1] + dp[i - 1][pj][c]) % MOD;
                        }else{
                           dp[i][pj][c] = (dp[i][pj][c] + dp[i - 1][pj][c]) % MOD;
                        }
                    }
                }
            }
        }
        
        for(int j = 1; j <= m; j++){
            res = (res + dp[n - 1][j][k]) % MOD;
        }
        
        return res;
    }
        
};