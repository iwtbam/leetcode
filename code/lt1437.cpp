// https://leetcode-cn.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
// check if all 1s are at least length k places away
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prek = -k - 1, size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums[i] == 1){
                if(i - prek - 1 < k)
                    return false;
                prek = i;
            }
        }
        
        return true;
    }
};