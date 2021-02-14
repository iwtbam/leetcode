// https://leetcode-cn.com/problems/the-k-weakest-rows-in-a-matrix/
// the k weakest rows in a matrix
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> infos = {};
        size_t rows = mat.size();
        for(int i = 0; i < rows; i++){
            int count = 0;
            size_t cols = mat[i].size();
            for(int j = 0; j < cols; j++){
                count += mat[i][j];
            }
            
            infos.push_back({count, i});
        }
        
        sort(infos.begin(), infos.end());
        
        vector<int> res = {};
        
        for(int i = 0; i < k && i < rows; i++)
            res.push_back(infos[i].second);
        
        return res;
    }
};