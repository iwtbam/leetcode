#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> record;
        vector<int> visited(nums.size(), 0);
        helper(res, nums, record, visited, nums.size());
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& nums, vector<int>& record, vector<int>& visited, int n){
        
        if(record.size() == n)
        {
            res.push_back(record);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                record.push_back(nums[i]);
                visited[i] = 1;
                helper(res, nums, record, visited, n);
                visited[i] = 0;
                record.pop_back();
            }
        }
        
    }
};