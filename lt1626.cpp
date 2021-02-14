// https://leetcode-cn.com/problems/best-team-with-no-conflicts/
// best team with no conflicts
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<int> dp(n, 0);
        
        vector<int> indexs(n, 0);
        iota(indexs.begin(), indexs.end(), 0);
        
        sort(indexs.begin(), indexs.end(), [&](int i, int j){ 
            return ages[i] < ages[j] || (ages[i] == ages[j] && scores[i] < scores[j]); 
        });
        
        // for(int i = 0; i < n; i++){
        //     cout << "(" << scores[indexs[i]]<<","<< ages[indexs[i]] << ") ";
        // }
        // cout << endl;
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            dp[i] = scores[indexs[i]];
            for(int j = 0; j < i; j++){
                if(scores[indexs[i]] >= scores[indexs[j]] || ages[indexs[i]] == ages[indexs[j]])
                    dp[i] = max(dp[i], dp[j] + scores[indexs[i]]);
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};