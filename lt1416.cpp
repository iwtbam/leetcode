// https://leetcode-cn.com/problems/restore-the-array/
// restore the array
class Solution {
public:
    int numberOfArrays(string s, int k) {
        const static int MOD = pow(10, 9) + 7;
        
        int size = s.size();
        int maxLen = to_string(k).size();
        vector<int> dp(size, 0);
        
        dp[0] = s[0] - '0'? 1 : 0;
        
        for(int i = 1; i < size; i++){
            dp[i] = s[i] == '0' ? 0 : dp[i - 1];
            for(int j = max(0, i - maxLen + 1); j <= i - 1; j++){
                if(s[j] == '0')
                    continue;
                int len = i - j + 1;
                if(stol(s.substr(j, len)) <= k){
                    dp[i] = (dp[i] + (j > 0 ? dp[j - 1] : 1)) % MOD;
                }
                
            }
        }
        
   
        
        return dp[size - 1];
        
    }
};