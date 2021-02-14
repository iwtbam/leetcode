#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<pair<int, int>>> res = {};
        vector<pair<int, int>> record;
        vector<int> rows(n, 0);
        vector<int> cols(n, 0);
        helper(res, record, rows, cols, 0, n);
        int s = res.size();
        cout << s << endl;
        return {};
    }

    void helper(vector<vector<pair<int,int>>>& res, 
                vector<pair<int, int>>& record, vector<int>& rows, vector<int>& cols, int step, int n){

        if(step == n)
        {
            res.push_back(record);
            return;
        }

      
        for(int j = 0;  j < n; j++)
        {
            if(cols[j]==0)
            {
                record.push_back({step, j});
                cols[j] = 1;
                helper(res, record, rows, cols, step + 1, n);
                cols[j] = 0;
                record.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    s.solveNQueens(2);
    return 0;
}