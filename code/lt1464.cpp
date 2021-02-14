// https://leetcode-cn.com/problems/maximum-product-of-two-elements-in-an-array/
// maximum product of two elements in an array
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(i == j)
                    continue;
                res = max(res, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        return res;
    }
};