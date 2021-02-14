// https://leetcode-cn.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
// minimum difference between largest and smallest value in three moves
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int diff = size - 3;
        int res = INT_MAX;
        for(int i = 0; i < size - diff + 1; i++){
            res = min(res, nums[i + diff - 1] - nums[i]);
        }
        return res;
    }

};