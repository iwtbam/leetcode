// https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
// nge tou zi de dian shu lcof
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<int> dp(n * 6 + 1, 0);
        for(int i = 1; i <= 6; i++){
            dp[i] = 1;
        }
        for(int i = 2; i <= n; i++){
            for(int v = 6 * n ; v >= i; v--){
                dp[v] = 0;
                for(int j = 1; j <= 6; j++){
                    if(v - j < i - 1)
                        break;
                    dp[v] = dp[v] + dp[v - j];
                }
            }
        }
        double interval = pow(1.0 / 6, n);
        vector<double> res = {};
        for(int i = n; i <= 6 * n; i++){
            res.push_back(interval * dp[i]);
        }   
        return res;
    }
};