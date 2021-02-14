// https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array/
// sum of absolute differences in a sorted array
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<int> sum = sorted_nums;
        size_t size = nums.size();
        
        for(int i = 1; i < size; i++)
            sum[i] = sorted_nums[i] + sum[i - 1];
        
        
        vector<int> res(size, 0);
        
        for(int i = 0; i < size; i++){
            int pos = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) - sorted_nums.begin();
            
            if(pos > 0){
                res[i] = (nums[i] * pos) - sum[pos - 1];  // [0, i - 1]
            }
            
            if(pos < size - 1){
                res[i] += sum[size - 1] - sum[pos] - nums[i] * (size - pos - 1); // [i + 1, size - 1]  size - i - 1
            }
        }
        
        return res;
    }
};