#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> item;
        helper(res,item, k, n, 1);
        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& item, int k, int n, int step)
    {
        if(k == 0 && n == 0)
        {
            res.push_back(item);
            return;
        }
        
        for(int i = step; i<=9;i++)
        {
            if(i > n)
                return;
            item.push_back(i);
            helper(res, item, k-1, n - i,i + 1);
            item.pop_back();
        }
    }
};