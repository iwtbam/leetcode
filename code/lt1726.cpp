// https://leetcode-cn.com/problems/tuple-with-same-product/
// tuple with same product
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> record;
        
        size_t size = nums.size();
        
        for(int i = 0; i < size - 1; i++){
            for(int j = i + 1; j < size; j++){
                record[nums[i] * nums[j]]++;
            }
        }
        
        int ans = 0;
        
        for(auto [k, v] : record){
            ans += v * (v - 1) * 4;
        }
        
        return ans;
    }
};