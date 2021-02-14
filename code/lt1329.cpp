// https://leetcode-cn.com/problems/sort-the-matrix-diagonally/
// sort the matrix diagonally
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();
        
        for(int i = 0; i < rows; i++)
            helper(mat, i, 0);
        
        for(int i = 1; i < cols; i++)
            helper(mat, 0, i);
        
        return mat;
    }
    
    void helper(vector<vector<int>>& mat, int x, int y){
        vector<int> temp = {};
        int sx = x, sy = y, i = 0;
        while(x < rows && y < cols){
            temp.push_back(mat[x++][y++]);
        }
        
        x = sx, y = sy;
        sort(temp.begin(), temp.end());
        while(x < rows && y < cols){
            mat[x++][y++] = temp[i++];
        }
    }
    
private:
    int rows;
    int cols;
};