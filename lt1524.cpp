// https://leetcode-cn.com/problems/number-of-sub-arrays-with-odd-sum/
// number of sub arrays with odd sum
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        size_t size = arr.size();
        vector<vector<int>> dp = {size, vector<int>(2, 0)};
        
        dp[0][1] = arr[0] % 2;
        dp[0][0] = 1 - dp[0][1];
        
        const int MOD = pow(10, 9) + 7;
        
        for(int i = 1; i < size; i++){
            if(arr[i] % 2 == 0){
                dp[i][1] = dp[i - 1][1];
                dp[i][0] = (dp[i - 1][0] + 1) % MOD;
            }else{
                dp[i][1] = (dp[i - 1][0] + 1) % MOD;
                dp[i][0] = dp[i - 1][1];
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < size; i++){
            ans = (ans + dp[i][1]) % MOD;
        }
        
        return ans;
    }
};