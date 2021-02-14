// https://leetcode-cn.com/problems/reconstruct-a-2-row-binary-matrix/
// reconstruct a 2 row binary matrix
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int size  = colsum.size();
        int count = 0;
        vector<vector<int>> res = {2, vector<int>(size, 0)};

        for(int i = 0; i < size; i++){
            if(colsum[i] == 2){
                upper--;
                lower--;
                colsum[i] = 0;
                res[0][i] = 1;
                res[1][i] = 1;
            }
            count += colsum[i];
        }
        
        if(count != upper + lower)
            return {};
        
        for(int i = 0; i < size; i++){
            
            
            int item = colsum[i];
            
            if(item == 0)
                continue;
            
            if(item == 1 && upper > 0){
                res[0][i] = 1;
                upper--;
            }
            
            res[1][i] = item - res[0][i];
            lower -= res[1][i];
        }
        
        if(upper == 0 && lower == 0)
            return res;
        
        return {};
    }
};