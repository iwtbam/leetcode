#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


#if defined S1
//2019-07-27:09-24 二维dp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        vector<vector<int>> dp = {rows, vector<int>(cols, 0)};
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
        
        for(int i = 1; i < rows; i++)
        {
            for(int j = 1; j < cols; j++)
            {
                if(dp[i][j])
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1 ;
            }
        }

        int maxRectSize = INT_MIN;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
                maxRectSize = max(maxRectSize, dp[i][j]);
        }
        

        return maxRectSize * maxRectSize;
    }
};

#elif defined S2
//二维优化成一维
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0){
            return 0;
        }
        
        int cols = matrix[0].size();
        vector<int> dp(cols, 0);
        int maxRectSize = INT_MIN;
            
        
        for(int i = 0; i < cols; i++){
            dp[i] = matrix[0][i] - '0';
            maxRectSize = max(maxRectSize, dp[i]);
        }
            
        
        for(int i = 1; i < rows; i++)
        {
            int pre = dp[0];
            dp[0] = matrix[i][0] - '0';
            maxRectSize = max(maxRectSize, dp[0]);
            for(int j = 1; j < cols; j++)
            {
             
                int temp = dp[j];
                if(matrix[i][j] - '0')
                    dp[j] = min(dp[j], min(dp[j-1], pre)) + 1;
                else
                    dp[j] = 0;
                
                pre = temp;
                maxRectSize = max(maxRectSize, dp[j]);
            }
            
        }
        
        return maxRectSize * maxRectSize;
    }
};

#endif