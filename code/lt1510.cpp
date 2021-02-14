// https://leetcode-cn.com/problems/stone-game-iv/
// stone game iv
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, false);
        vector<int> fetch;        
        for(int i = 1; i * i <= n; i++){
            dp[i * i] = 1;
            fetch.push_back(i * i);
        }
        
        int size = fetch.size();
        // dp[0] = false;
        
        for(int i = 2; i <= n; i++){
            int sq = sqrt(i);
            if(sq * sq == i)
                continue;
            for(int j = 0; j < size; j++){
                if(fetch[j] <= i)
                    dp[i] = dp[i] || !dp[i - fetch[j]];
            }
        }
        
//         for(int i = 0; i <=n ;i++)
//             cout << dp[i] << " ";
//         cout << endl;
        
        return dp[n];
    }
};