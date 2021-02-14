// https://leetcode-cn.com/problems/number-of-music-playlists/
// number of music playlists
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long long>> dp = {static_cast<size_t>(L + 1), vector<long long>(N + 1, 0)};
        
        const int MOD = pow(10, 9) + 7;

        dp[0][0] = 1;
        
        for(int i = 1; i <= L; i++){
            for(int k = 1; k <= N; k++){
               
                dp[i][k] = (dp[i][k] + dp[i - 1][k - 1] * (N - k + 1)) % MOD;
                if(k - 1 >= K){
                    dp[i][k] = (dp[i][k] + dp[i - 1][k] * (k - K)) % MOD;
                }
            }
        }


        return dp[L][N];
    }
};