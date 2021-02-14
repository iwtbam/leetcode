// https://leetcode-cn.com/problems/power-set-lcci/
// power set lcci
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, res, path, 0);
        return res;
    }


    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int step){
        res.push_back(path);
        size_t size = nums.size();
        for(int i = step; i < size; i++){
            path.push_back(nums[i]);
            dfs(nums, res, path, i + 1);
            path.pop_back();
        }
        return;        
    }
};