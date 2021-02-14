// https://leetcode-cn.com/problems/maximum-absolute-sum-of-any-subarray/
// maximum absolute sum of any subarray
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_val = 0, neg = 0, pos = 0;
        size_t n = nums.size();
        for(int i = 0; i < n; i++){
            pos += nums[i];
            neg += nums[i];
            
            if(pos < 0)
                pos = 0;
            if(neg > 0)
                neg = 0;
            
            max_val = max(max_val, pos);
            max_val = max(max_val, abs(neg));
        }
        
        return max_val;
    }
};