// https://leetcode-cn.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
// minimum number of taps to open to water a garden
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, INT_MAX);
        int size = ranges.size();
        // dp[0] = 0;
        for(int i = 0; i < size; i++){
            
            int start = i - ranges[i];
            int end = i + ranges[i];
            if(start  < 0)
                start = 0;
            if(end > n)
                end = n;
            
            int pre = start == 0 ? 0 : dp[start];
            
            if(pre != INT_MAX){
                for(int j = start + 1; j <= end; j++){
                    dp[j] = min(dp[j], pre + 1); 
                }    
            }
        
        }
        
        if(dp[n] == INT_MAX)
            return -1;
        return dp[n];
    }
};