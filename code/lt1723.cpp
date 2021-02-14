// https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/
// find minimum time to finish all jobs
class Solution {
public:

    int dp[13][1 << 12];
    int sums[1 << 12];

    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        //vector<vector<int>> dp(k + 1, vector<int>(1 << n, INT_MAX));
        //vector<int> sums(1 << n, 0);

        memset(dp, 0x3f, sizeof(dp));
        memset(sums, 0, sizeof(sums));

        for(int i = 0; i < 1 << n; i++){
            for(int j = 0; j < n; j++){
                if(i >> j & 1)
                    sums[i] += jobs[j];
            }
        }

        dp[0][0] = 0;

        for(int i = 1; i <= k; i++){
            for(int s = 0; s < 1 << n; s++){
                for(int s1 = s; s1; s1 = (s1 - 1) & s){
                    dp[i][s] = min(dp[i][s], max(dp[i - 1][s ^ s1], sums[s1]));
                }
            }
        }

        return dp[k][(1 << n) - 1];
    }
};