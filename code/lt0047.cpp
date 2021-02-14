#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> record;
        sort(nums.begin(), nums.end());
        vector<int> visited(nums.size(), 0);
        helper(res, nums, record, visited);
        return res;
    }
    
    void helper(vector<vector<int>>& res, const vector<int>& nums, vector<int>& record, vector<int>& visited)
    {
        if(record.size() == nums.size())
        {
            res.push_back(record);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(visited[i])
                continue;
            
            if(i > 0 && nums[i]==nums[i-1] && !visited[i-1])
                continue;
            
            visited[i] = 1;
            record.push_back(nums.at(i));
            helper(res, nums, record, visited);
            record.pop_back();
            visited[i] = 0;
            
        }
        
    }
};