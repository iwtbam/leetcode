// https://leetcode-cn.com/problems/range-sum-of-sorted-subarray-sums/
// range sum of sorted subarray sums
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum = {};
        vector<int> prefix_sum(n + 1);
        
        const int MOD = pow(10, 9) + 7;
        for(int i = 0; i < n; i++){
            prefix_sum[i + 1] = (prefix_sum[i] + nums[i]) % MOD;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                sum.push_back((prefix_sum[j + 1] - prefix_sum[i] + MOD)%MOD) ;
            }
        }
        
        sort(sum.begin(), sum.end());
        
        int res = 0;
        
        for(int i = left - 1; i < right; i++){
            res = (res + sum[i]) %MOD;
        }
        
        return res;
    }
};