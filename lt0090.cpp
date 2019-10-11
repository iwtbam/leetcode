#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> record;
        sort(nums.begin(), nums.end());
        helper(res, record, nums, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& record, vector<int>& nums, int step){
        if(step > nums.size())
            return;
        
        res.push_back(record);

        
        for(int i = step;  i< nums.size(); i++)
        {
            if(i!=0 && i - 1 >= step && nums[i]==nums[i-1])
                continue;
            record.push_back(nums[i]);
            helper(res, record, nums, i+1);
            record.pop_back();
        }
    }
};