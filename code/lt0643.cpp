// https://leetcode-cn.com/problems/maximum-average-subarray-i/
// maximum average subarray i
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, ans = 0;
        int n = nums.size();

        for(int i = 0; i < k; i++)
            sum = sum + nums[i];

        ans = sum;
        for(int i = k; i < n; i++){
            sum = sum - nums[i - k] + nums[i];
            if(sum > ans)
                ans = sum;
        }

        return ans / k;
    }
};