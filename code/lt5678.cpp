// https://leetcode-cn.com/problems/minimum-limit-of-balls-in-a-bag/
// minimum limit of balls in a bag
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        long long l = 1, r = 1e9;
        while(l < r){
            long long cost = (l + r) >> 1;
            if(check(nums, cost, maxOperations)){
                r = cost; 
            }else{
                l = cost + 1;
            }
        }
        
        return l;
    }
    
    bool check(const vector<int>& nums, int cost, int op){
        int ans = 0;
        size_t n = nums.size();
        for(int i = 0; i < n; i++){
            ans = ans + nums[i] / cost - (nums[i] % cost == 0);
        }
        return ans <= op;
    }
};