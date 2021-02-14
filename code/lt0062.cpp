// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 问总共有多少条不同的路径？

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> vec(n, 1);
        vector<vector<int>> vec2(m, vec);
    
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                vec2[i][j] = vec2[i-1][j] + vec2[i][j-1];
            }
        }

        return vec2[m-1][n-1];      
    }
};

int main()
{
    Solution s;
    int r = s.uniquePaths(3, 2);
    cout << r << endl;
    r = s.uniquePaths(7, 3);
    cout << r << endl;
    return 0;
}