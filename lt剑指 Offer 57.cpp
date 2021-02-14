// https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
// he wei sde liang ge shu zi lcof
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> record;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(record.count(target - nums[i]))
                return {target - nums[i], nums[i]};
            record.insert(nums[i]);
        }

        return {};
    }
};