// https://leetcode-cn.com/problems/decompress-run-length-encoded-list/
// decompress run length encoded list
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int size = nums.size();
        vector<int> res = {};
        for(int i = 0; i < size; i += 2){
            int num = nums[i];
            for(int j = 0; j < num; j++)
                res.push_back(nums[i + 1]);
        }
        
        return res;
    }
};