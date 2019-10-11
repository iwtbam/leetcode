#include <vector>

using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        size_t row = matrix.size();
        if(row == 0)
            return false;
        size_t col =  matrix[0].size();
        int x = row - 1, y = 0;
        
        while(x >= 0 && x < row || y >= 0 || y < col)
        {
            if(matrix[x][y] > target)
                y += 1;
            else if(matrix[x][y] < target)
                x -= 1;
            else
                return true;
            
        }

        return false;
    }
};