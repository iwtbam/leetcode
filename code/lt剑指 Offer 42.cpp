// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
// lian xu zi shu zu de zui da he lcof
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_res = INT_MIN;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            sum += nums[i];
            max_res = max(max_res, sum);
            if(sum < 0)
                sum = 0;
        }
        return max_res;
    }
};