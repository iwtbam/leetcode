#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty())
            return 0;
        int size = s.size();
        vector<vector<int>> dp = {size, vector<int>(size, 0)};
        for(int i = 0; i < size; i++)
            dp[i][i] = 1;
        
        int res = size;

        for(int i = 1; i <= size - 1;i++)
        {
            for(int j = 0; j< size - i;j++)
            {
                int inc =  s[j] == s[j+i] ? 1 : 0;
                if(i == 1)
                    dp[j][j+i] = inc;
                else
                    dp[j][j+i] = dp[j+1][j+i-1] == 1 && inc == 1;
                
                res += dp[j][j+i];
            }
                           
        }

        return res;
    }
};