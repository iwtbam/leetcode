#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res = {};
        vector<int> record = {};
        sort(candidates.begin(), candidates.end());
        helper(res, candidates, record, target, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& candidates, vector<int>& record , int target,int step){
        if(target < 0)
            return;
        
        if(target == 0)
        {
            res.push_back(record);
            return;
        }
        
        for(int i = step; i < candidates.size(); i++)
        {
            if(candidates[i] > target)
                return;
            
            record.push_back(candidates[i]);
            helper(res, candidates, record, target - candidates[i], i);
            record.pop_back();
        }
        
        vector<int>::reverse_iterator
    }
};