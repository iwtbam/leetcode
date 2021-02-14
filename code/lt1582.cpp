// https://leetcode-cn.com/problems/special-positions-in-a-binary-matrix/
// special positions in a binary matrix
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        if(rows == 0)
            return 0;
        int cols = mat[0].size();
        vector<int> ro(rows, 0);
        vector<int> co(cols, 0);
        for(int i = 0; i < rows; i++){
            for(int j= 0;j < cols; j++){
                if(mat[i][j] == 0)
                    continue;
                ro[i]++;
                co[j]++;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                ans += (mat[i][j] == 1 && ro[i] == 1 && co[j] == 1);
            }
        }
        
        return ans;
    }
};