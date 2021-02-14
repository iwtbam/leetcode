// https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
// single element in a sorted array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = nums[0];
        size_t size  = nums.size();
        for(int i = 1; i < size; i++)
            res = res ^ nums[i];
        return res;
    }
};