// https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended-ii/
// maximum number of events that can be attended ii
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        vector<int> days;
        size_t n = events.size();
        for(int i = 0; i < n; i++){
            days.push_back(events[i][0]);
            days.push_back(events[i][1]);
        }
        
        sort(days.begin(), days.end());
        int size = unique(days.begin(), days.end()) - days.begin();
        
        unordered_map<int, int> record;
        
        for(int i = 0; i < size; i++){
            record[days[i]] = i + 1;
        }
        
        unordered_map<int, vector<pair<int, int>>> es;
        
        for(int i = 0; i < n; i++){
            int e = record[events[i][1]];
            int s = record[events[i][0]];
            int v = events[i][2];
            es[e].emplace_back(s - 1, v);
        }
        
        vector<vector<int>> dp(size + 1, vector<int>(k + 1, -1));
        
        for(int i = 0; i <= size; i++)
            dp[i][0] = 0;
        
        // dp[]
        
        int ans = 0;
        
        for(int i = 1; i <= size; i++){
            auto e = es[i];
            for(int j = 1; j <= k; j++){
                dp[i][j] = dp[i - 1][j];
                for(auto [s, v] : e){
                    if(dp[s][j - 1] == -1)
                        continue;
                    dp[i][j] = max(dp[i][j], dp[s][j - 1] + v);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};