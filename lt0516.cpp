#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty())
            return 0;

        int size = s.size();
        vector<vector<int>> dp = {size, vector<int>(size, 0)};
        
        for(int i = 0; i < size; i++)
            dp[i][i] = 1;
        
        for(int i = 1; i < size; i++)
        {
            for(int j = 0; j < size - i; j++)
            {
                int equal = s[j] == s[j+i] ? 2 : 0;
                if(i==1)
                    dp[j][j+i] = max(1, equal) ;
                else
                {
                    dp[j][j+i] = max(max(dp[j+1][j+i], dp[j][j+i-1]), dp[j+1][j+i-1] + equal); 
                }
             
            }
            
        
        }

        return dp[0][size-1];
    }
};