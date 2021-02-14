// https://leetcode-cn.com/problems/check-if-array-is-sorted-and-rotated/
// check if array is sorted and rotated
class Solution {
public:
    bool check(vector<int>& nums) {
        size_t n = nums.size();
        int part = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1])
                part++;
            
            if(part > 1)
                return false;
            
            if(part == 0 && nums[i] < nums[0])
                return false;
            if(part == 1 && nums[i] > nums[0])
                return false;
        }
        
        return true;
        
    }
};