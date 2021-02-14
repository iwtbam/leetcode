// https://leetcode-cn.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/
// check if a number is majority element in a sorted array
class Solution {
public:
    
    bool isMajorityElement(vector<int>& nums, int target) {
        int size = upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target);
        return size * 2 > nums.size();
    }
};