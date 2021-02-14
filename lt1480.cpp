// https://leetcode-cn.com/problems/running-sum-of-1d-array/
// running sum of 1d array
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        
        int size = nums.size();
        int sum = 0;
        for(int i = 0; i < size; i++){
            sum += nums[i];
            res.push_back(sum);
        }
        
        
        return res;
    }
};