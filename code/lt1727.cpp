// https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/
// largest submatrix with rearrangements
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        auto heights = matrix[0];
        int area = accumulate(heights.begin(), heights.end(), 0);
        
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                heights[j] = matrix[i][j] == 0 ? 0 : heights[j] + matrix[i][j];   
            }
            
            auto aux = heights;
            sort(aux.begin(), aux.end());
            for(int j = 0; j < n; j++){
                area = max(area, aux[j] * (n - j));
            }
        }
        return area;
    }
};