// https://leetcode-cn.com/problems/sorted-matrix-search-lcci/
// sorted matrix search lcci
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0)
            return false;

        int cols = matrix[0].size();
        int x = rows - 1, y = 0;
        
        while(x >= 0 && y < cols){
            if(matrix[x][y] == target)
                return true;
            
            if(matrix[x][y] < target){
                y++;
            }else{
                x--;
            }
        }

        return false;
    }
};