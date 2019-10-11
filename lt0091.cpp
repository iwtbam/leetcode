#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if(size == 0)
            return 0;
        vector<int> dp(size + 2, 0);
        dp[0] = s[0] == '0' ? 0 : 1;
        if(size == 1)
            return dp[0];
        
        dp[1] = s[1] == '0' ? 0 : dp[0];
        
        if(s[0] != '0' && ((s[0] - '0') * 10 + s[1] - '0') <=26)
            dp[1] = dp[1] + 1;
            
        
        if(size == 2)
            return dp[1];
      
        
        for(int i = 2; i < size; i++)
        {
            dp[i] = s[i] == '0' ? 0 : dp[i-1]; 
            if(s[i-1] == '0')
                continue;
            
            int num = (s[i-1] - '0') * 10 + s[i] - '0';
            if(num >= 1 && num <= 26)
                dp[i] += dp[i-2];
        }

        return dp[size - 1];

    }
};