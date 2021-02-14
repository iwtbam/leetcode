// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
// er wei shu zu zhong de cha zhao lcof
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0)
            return false;
        int cols = matrix[0].size();
        if(cols == 0)
            return false;
        
        int x = rows - 1, y = 0;
        while(x >= 0 && y < cols){
            if(target == matrix[x][y])
                return true;
            
            if(target > matrix[x][y]){
                y++;
            }else{
                x--;
            }
        }

        return false;
    }
};