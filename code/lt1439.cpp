// https://leetcode-cn.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
// find the kth smallest sum of a matrix with sorted rows
class Solution {
public:
   
    int kthSmallest(vector<vector<int>>& mat, int k) {
        size_t rows = mat.size();
        size_t cols = mat[0].size();

        vector<int> res = {mat[0].begin(), mat[0].begin() + min(static_cast<size_t>(k), cols)};
        for(int i = 1; i < rows; i++){
            vector<int> nres = {};
            int cap = res.size();

            for(int j = 0; j < cols; j++){
                for(int v = 0; v < cap; v++){
                    nres.push_back(res[v] + mat[i][j]);
                }
            }
            sort(nres.begin(), nres.end());
            
            res = vector<int>{nres.begin(), nres.begin() + min(static_cast<size_t>(k), nres.size())};
        }

        return res.back();
    }
};