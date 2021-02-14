// https://leetcode-cn.com/problems/minimum-subsequence-in-non-increasing-order/
// minimum subsequence in non increasing order
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> res = {};
        size_t size = nums.size();
        int sum = 0;
        for(int i = 0; i < size; i++){
            sum += nums[i];
            res.push_back(nums[i]);
            if(sum * 2 > total) {
                return res;
            }
        }
        
        return {};
    }
};