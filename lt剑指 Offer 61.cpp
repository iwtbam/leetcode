// https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
// bu ke pai zhong de shun zi lcof
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int zero = 0, min_e = 13, max_e = 1;
        int size = nums.size();

        unordered_set<int> set;
        for(int i = 0; i < size; i++){
            if(nums[i] == 0){
                zero++;
                continue;
            }

            if(set.count(nums[i]))
                return false;
            
            set.insert(nums[i]);

            min_e = min(min_e, nums[i]);
            max_e = max(max_e, nums[i]);
        } 

        int len = max_e - min_e + 1;
        if(len > 5)
            return false;
        
        return len + zero >= 5;
    }
};