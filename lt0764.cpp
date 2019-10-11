#include <vector>

using namespace std;

class Solution {
public:

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grids = {N, vector<int>(N, 1)};
        
        for(auto& mine:mines)
        {
            grids[mine[0]][mine[1]] = 0;
        }
        int max_n = 0;

        for(int i = 0; i < N - max_n; i++)
        {
            for(int j = max_n; j < N - max_n; j++)
            {
                if(grids[i][j])
                    max_n = max(max_n, helper(grids, N, i, j));
                i = max(max_n - 1, i);
            }
        }
        
       

        return max_n;
    }
    
    int helper(vector<vector<int>>& grids, int N, int i, int j)
    {
        int num = 1;
        while(num)
        {
            for(int k = 0; k < 4; k++)
            {
                int ni = i + dx[k] * num;
                int nj = j + dy[k] * num;

                if(ni < 0 || ni >= N || nj <0 || nj >= N || grids[ni][nj]==0)
                    return num;
              
            }
            num++;
        }
        return num;
    }
};