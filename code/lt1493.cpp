// https://leetcode-cn.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// longest subarray of 1s after deleting one element
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero = 0;
        int l = 0, r = 0, size = nums.size();
        int len = 0;
        while(r < size){
            if(nums[r] == 0)
                zero++;
            
            while(l < r && zero > 1){
                if(nums[l] == 0){
                    zero--;
                }
                l++;
            }
            
            len = max(len, r - l);
            r++;
        }
        
        len = max(len, r - l - 1);
        
        return len;
    }
};