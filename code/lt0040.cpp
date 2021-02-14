#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() == 0)
            return {};
        vector<vector<int>> res = {};
        vector<int> record = {};
        
        sort(candidates.begin(), candidates.end());
        
        helper(res, candidates, record, target , 0);
        
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& candidates,  vector<int>& record, int target, int step)
    {
        if(target == 0)
        {
            res.push_back(record);
            return;
        }
        
        if(target  < 0)
            return;
        
        for(int i = step; i < candidates.size(); i++)
        {
            if(candidates[i] > target)
                return;
            
            if(i > step && candidates[i-1] == candidates[i])
                continue;
            
            record.push_back(candidates[i]);
            helper(res, candidates, record, target - candidates[i], i + 1);
            record.pop_back();
        }
    }
};