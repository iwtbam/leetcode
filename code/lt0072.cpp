#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//2019-06-05:14-50:感觉字符串匹配的dp 主要还是找 dp[i][j] 和 dp[i-1][j], dp[i][j-1], d[i-1][j-1]的关系

class Solution
{
public:
    int minDistance(string word1, string word2){
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp = {len1 + 1, vector<int>(len2 + 1, 0)};

        for(int i = 0; i <= len1; i++)
            dp[i][0] = i;
        
        for(int j = 0; j <= len2; j++)
            dp[0][j] = j;

        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j<=len2; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1] - 1));
                else 
                    dp[i][j] = 1 +min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }

        return dp[len1][len2];
    }
};

int main()
{

    // vector<vector<int>> vv = {5, vector<int>(10)};
    // // vector<int> v(10);
    // size_t size = vv.size();
    // size_t size2 = vv[0].size();
    // cout << size << endl;
    // cout << size2 << endl;
    return 0;
}