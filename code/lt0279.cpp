#include <vector>
#include <cmath>
using namespace std;


#if defined S1

//2019-07-31:回溯,超时,简单,但没用

class Solution {
public:
    int numSquares(int n) {
        int sn = sqrt(n);
        int min_num = INT_MAX;
        helper(sn, n, 1, 0, min_num);
        return min_num;
    }

    void helper(int max_num, int target, int step, int times,  int& min_num)
    {
        if(target == 0)
        {
            min_num = min(times, min_num);
            return;
        }

        for(int i = step; i <= max_num; i++)
        {
            if(target < i * i)
                return;
            helper(max_num, target - i * i, step, times+1, min_num);
        }
    }
};

#elif defined S2

//2019-07-31:18-27 dp 勉强通过, 不优
//2019-07-31:18-30 看了题解, 有人用bfs, 有点东西

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(n+1, n);
        vector<int> res = {};
        int sqrt_n = sqrt(n);
        for(int i = 1; i <= sqrt_n; i++)
            res.push_back(i*i);
        
        dp[0] = 0;
        
        for(int i = 1; i <=n;i++)
        {
            for(int j = 0; j < sqrt_n; j++)
                dp[i] = min( i >= res[j] ? dp[i - res[j]] + 1:dp[i], dp[i]); 
        }
        
        return dp[n];
    }

};

#endif