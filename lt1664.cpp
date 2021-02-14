// https://leetcode-cn.com/problems/ways-to-make-a-fair-array/
// ways to make a fair array
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        size_t n = nums.size();
            
        if(n == 2)
            return 0;
        
        if(n == 1)
            return 1;
        
        vector<vector<int>> sums(n + 1, vector<int>(2));
        sums[1][0] = nums[0];
        sums[1][1] = 0;
        sums[2][0] = nums[0];
        sums[2][1] = nums[1];
        
        for(int i = 2; i < n; i++)
        {
            sums[i + 1][i % 2] = sums[i][i % 2] + nums[i];
            sums[i + 1][(i + 1) % 2] = sums[i][(i + 1) % 2];
        }
        
       
        int ans = 0;
        int lo = 0, le = 0, ro = 0, re = 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                lo = 0;
                le = 0;
            }else{
                lo = sums[i][0];
                le = sums[i][1];
            }
            
            if(i == n - 1){
                ro = 0;
                re = 0;
            }else{
                ro = sums[n][1] - sums[i + 1][1];
                re = sums[n][0] - sums[i + 1][0];
            }
            
            ans += (lo + ro) == (le + re);
        }
        
        return ans;
            
    }
};