// https://leetcode-cn.com/problems/cells-with-odd-values-in-a-matrix/
// cells with odd values in a matrix
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> matrix = {n, vector<int>(m, 0)};
        
        for(const vector<int>& indice : indices){
            int r = indice[0];
            int c = indice[1];
            for(int i = 0; i < m; i++){
                matrix[r][i]++;
            }
            
            for(int i = 0; i < n; i++){
                matrix[i][c]++;
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                count += matrix[i][j] % 2;
            }
        }
        
        return count;
    }
};