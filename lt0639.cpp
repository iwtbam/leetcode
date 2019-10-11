#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if(size == 0)
            return 0;
        vector<long long> dp(size, 0);    
        
        dp[0] = valid_num(s[0]);
        
        if(size == 1)
            return dp[0];
        
        dp[1] = dp[0] * valid_num(s[1]);
        dp[1] = dp[1] + valid_num(s[0], s[1]);
            
        int mod = pow(10, 9) + 7;
        
        if(size == 2)
            return dp[1];
      
        
        for(int i = 2; i < size; i++)
        {
            dp[i] =  (dp[i-1] * valid_num(s[i])) % mod ; 
            dp[i] =  (dp[i] + dp[i-2] * valid_num(s[i-1], s[i])) % mod;
        }

        return dp[size - 1];
        
    }
    
    inline int valid_num(char cur)
    {
        return cur == '0' ? 0 : (cur == '*' ? 9  : 1);
    }
    
    inline int valid_num(char pre, char cur)
    {
        if(pre == '0')
            return 0;
        
        if(pre == '*' && cur == '*')
            return 15;
        
        if(pre == '*')
            return cur > '6'? 1 : 2;
        
        if(cur == '*')
            return pre > '2' ? 0 : (pre > '1' ?  6: 9);
        
        return ((pre - '0') * 10 + (cur - '0')) <= 26 ? 1 : 0;
    }
};