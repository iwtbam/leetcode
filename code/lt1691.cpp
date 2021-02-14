// https://leetcode-cn.com/problems/maximum-height-by-stacking-cuboids/
// maximum height by stacking cuboids
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {

        size_t size = cuboids.size();
        for(int i = 0; i < size; i++)
            sort(cuboids[i].begin(), cuboids[i].end());

        sort(cuboids.begin(), cuboids.end(), [](const vector<int>& v1, const vector<int>& v2){
            return pair<int, int>(v1[2], v1[0] + v1[1]) > pair<int, int>(v2[2], v2[0] + v2[1]);
        });


        vector<int> dp(size, 0);
        int ans = 0;
        for(int i = 0; i < size; i++){
            dp[i] = cuboids[i][2];
            for(int j = 0; j < i; j++){
                if(cuboids[i][0] <= cuboids[j][0] && cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2]){
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    
    }
};