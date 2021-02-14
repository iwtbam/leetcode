// https://leetcode-cn.com/problems/subarray-product-less-than-k/
// subarray product less than k
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        long long res = 1;
        int count = 0;
        int size = nums.size();
        while(right < size){
            res *= nums[right];
         
            while(left <= right && res >= k){
                res /= nums[left];
                left++;
            }

            if(res < k)
                count += right - left + 1;

            right++;
        }

        return count; 
    }
};