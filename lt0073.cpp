#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row =  matrix.size();
        
        if(row == 0)
            return;
        int col = matrix[0].size();
        
        vector<int> rows;
        vector<int> cols;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }


        for(int i = 0; i < rows.size(); i++)
        {
            for(int j = 0; j < col; j++)
                matrix[rows[i]][j] = 0;
        }

        for(int i = 0; i < cols.size(); i++)
        {
            for(int j = 0; j < row; j++)
                matrix[rows[j]][i] = 0;
        }

        return;
              
    }
};