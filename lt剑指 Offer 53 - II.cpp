// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
// que shi de shu zi lcof
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            // if(mid == nums.size())
            //     return mid;
            if(nums[mid] == mid){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};