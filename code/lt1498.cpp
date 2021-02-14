// https://leetcode-cn.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
// number of subsequences that satisfy the given sum condition
class Solution {
public:

    const int MOD = pow(10, 9) + 7;

    long long quickpow(long long base, int e){
        long long res = 1;
        while(e){
            if(e & 1){
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            e = e >> 1;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int res = 0;
        while(left <= right){
            while(left < right && nums[left] + nums[right] > target){
                right--;
            }

            if(nums[left] + nums[right] > target)
                return res;

            res = (res + quickpow(2, right - left)) % MOD;
            left++;
        }

        return res;
    }
};