#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


#if defined(S1)

//2019-06-05:14-12 自顶向下, 不好

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int size = triangle.size();

        if(size == 0)
            return 0;

        vector<int> dp(size, 0);
        dp[0] = triangle[0][0];

        for(int i = 1; i < size;i++)
        {
            for(int j = i;j >=0 ; j--)
            {
                if(j == i)
                    dp[j] = dp[j-1];
                else if(j == 0)
                    dp[j] == dp[j];
                else
                    dp[j] = min(dp[j], dp[j-1]);

                dp[j] = dp[j] + triangle[i][j];
            }
        }

        int m = dp[0];
        for(int i = 1; i < size ; i++)
            m = min(dp[i], m);

        return m;        
    }
};

#else

//2019-06-05:14-19 自底向上, 很明了

class Solution {
public:
      
     Solution(){
         std::ios::sync_with_stdio(false);
     }
    
     int minimumTotal(vector<vector<int>>& triangle){
        int size = triangle.size();

        if(size == 0)
            return 0;

        vector<int> dp {triangle[size - 1]};
        
        for(int i = size - 2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }

        return dp[0];        
    }
};

#endif