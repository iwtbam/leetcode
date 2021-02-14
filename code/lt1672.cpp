// https://leetcode-cn.com/problems/richest-customer-wealth/
// richest customer wealth
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        size_t rows = accounts.size();
        int res = 0;
        for(int i = 0; i < rows; i++){
            int total = 0;
            int cols = accounts[i].size();
            for(int j = 0; j < cols; j++)
                total += accounts[i][j];
            res = max(res, total);
        }
        
        return res;
    }
};