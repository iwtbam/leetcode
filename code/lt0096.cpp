#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <=n ;i++)
        {
            for(int j = 0; j < i ; j++)
                dp[i] += dp[i - j - 1] * dp[j];
        }
        return dp[n];
    }
};