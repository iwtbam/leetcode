// https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/
// zheng ze biao da shi pi pei lcof
class Solution {
public:
    bool isMatch(string s, string p) {
        int sL = s.size();
        int pL = p.size();
        vector<vector<int>> dp(sL + 1, vector<int>(pL + 1, 0));

        dp[0][0] = 1;

        for(int i = 2; i <= pL; i++){
            if(p[i - 1] == '*'){
                dp[0][i] = dp[0][i - 2];
            }
        }

        for(int i = 1; i <= sL; i++){
            for(int j = 1; j <= pL; j++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    if(p[j - 1] == '*'){
                        dp[i][j] = dp[i][j - 1];
                        if(j >= 2){
                            dp[i][j] = dp[i][j] || dp[i][j - 2] ||  ((dp[i - 1][j - 1] || dp[i - 1][j]) && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                        }
                    }
                }
            }
        }
        return dp[sL][pL];
    }
};

//       a    a   b    *
//   a   1    0   0    0
//   a   0    1   0    1
//   b   0    0   1    1
//   b   0    0   0    1 
//   b   0    0   0    