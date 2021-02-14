// https://leetcode-cn.com/problems/number-of-good-pairs/
// number of good pairs
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        stable_sort(nums.begin(), nums.end());
        int res = 0, len = 0, size = nums.size();
        for(int i = 0; i < size - 1; i++){
            if(nums[i] == nums[i + 1]){
                len++;
            }else{
                res += len * (len + 1) / 2;
                len = 0;
            }
        }
        
        res += len * (len + 1) / 2;
        
        return res;
    }
};