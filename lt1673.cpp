// https://leetcode-cn.com/problems/find-the-most-competitive-subsequence/
// find the most competitive subsequence
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        size_t size = nums.size();
        
        if(size == k)
            return nums;
        
        vector<int> indexs;
        for(int i = 0; i < size; i++){
            while(indexs.size() && (indexs.size() + size - i > k && nums[i] < nums[indexs.back()]))
                indexs.pop_back();
            indexs.push_back(i);
        }
        
        vector<int> res;
        
        for(int i = 0; i < k; i++)
            res.push_back(nums[indexs[i]]);
        
        return res;
    }
};