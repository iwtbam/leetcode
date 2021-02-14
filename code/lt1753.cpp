// https://leetcode-cn.com/problems/maximum-score-from-removing-stones/
// maximum score from removing stones
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> nums = {a, b, c};
        int ans = 0;
        
        while(!check(nums)){
            sort(nums.begin(), nums.end());
            int diff = nums[1] - nums[0];
            if(diff == 0)
                diff = 1;
            nums[1] -= diff;
            nums[2] -= diff;
            ans += diff;
        }
        
        return ans;
    }
    
    inline bool check(const vector<int>& nums){
        int zero = 0;
        for(int i = 0; i < nums.size(); i++)
            zero += (nums[i] == 0);
        return zero >= 2;
    }
};