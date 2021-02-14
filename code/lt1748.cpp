// https://leetcode-cn.com/problems/sum-of-unique-elements/
// sum of unique elements
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int record[105] = {0};
        size_t n = nums.size();
        for(int i  = 0; i < n; i++)
            record[nums[i]]++;
        
        int ans = 0;
        for(int i = 0; i < 105; i++){
            if(record[i] == 1)
                ans += i;
        }
        
        return ans;
    }
};