// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int len1 = obstacleGrid.size();
        int len2 = len1 ? obstacleGrid[0].size() : 0;

        if(!(len2 && len1))
            return 0;
        
        vector<int> vec(len2, 0);
        vector<vector<int>> vec2(len1, vec);

        for(int i = 0; i < len2; i++)
        {
            if(obstacleGrid[0][i])
                break;
            vec2[0][i] = 1;
        }

        for(int i = 0; i < len1; i++)
        {
            if(obstacleGrid[i][0])
                break;
            vec2[i][0] = 1;
        }

        for(int i = 1; i < len1; i++)
        {
            for(int j = 1; j< len2; j++)
            {
                vec2[i][j] = obstacleGrid[i][j] ? 0 : ( vec2[i-1][j] + vec2[i][j-1]); 
            }
        }

        return vec2[len1 - 1][len2 - 1];
    }
};

int main()
{
    vector<vector<int>> vec2 = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    Solution s;

    int r = s.uniquePathsWithObstacles(vec2);

    cout << r << endl;

    return 0;
}