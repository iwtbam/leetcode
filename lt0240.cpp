#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0)
            return false;
        int cols = matrix[0].size();

        int x = rows - 1, y = 0;

        while(x >=0 &&  y < cols)
        {
            if(target == matrix[x][y])
                return true;
            if(target > matrix[x][y]){
                y++;
                continue;
            }
            if(target < matrix[x][y])
                x--;
        }
        
        return false;
    }
};