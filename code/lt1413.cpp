// https://leetcode-cn.com/problems/minimum-value-to-get-positive-step-by-step-sum/
// minimum value to get positive step by step sum
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        size_t size = nums.size();
        int cost = 0;
        int sum = 0;
        for(int i = 0; i < size; i++){
            sum += nums[i];
            if(sum < 0){
                cost = max(cost, -sum);
            }
        }
        return cost + 1;
    }
};