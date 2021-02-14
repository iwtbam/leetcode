#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> record;
        helper(res, record, nums, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& record, vector<int>& nums, int step){
        
        res.push_back(record);
        
        if(nums.size() == step)
            return;
        
        for(int i = step; i < nums.size(); i++)
        {
            record.push_back(nums[i]);
            helper(res, record, nums, i + 1);
            record.pop_back();
        }
        
    }
};