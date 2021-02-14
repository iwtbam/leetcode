// https://leetcode-cn.com/problems/maximum-erasure-value/
// maximum erasure value
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> sums(n + 1, 0);
        
        for(int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];
        
        int l = 0, r = 0;
        int res = 0;
        
        unordered_set<int> record;
        
        while(r < n){
            
            while(l <= r && record.count(nums[r])){
                record.erase(nums[l]);
                l++;
            }
            record.insert(nums[r]);
            res = max(res, sums[r + 1] - sums[l]);
            r++;
        }
        
        if(check())
            res = max(res, sums[n] - sums[l]);        
        return res;
    }
    
    bool check(){
        for(int i = 0; i < 10; i++)
            if(record[i] > 1)
                return false;
        return true;
    }
    
private:
    int record[10];
};