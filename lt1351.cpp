// https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix/
// count negative numbers in a sorted matrix
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(),  n = grid[0].size();
        int j = n - 1, ans = 0, count = 0;
        for(int i = 0; i < m; i++){
            while(j >= 0 && grid[i][j] < 0){
                j--;
                count++;
            }
            ans += count;
        }
        
        return ans;
    }
};