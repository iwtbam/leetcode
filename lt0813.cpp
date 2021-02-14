// https://leetcode-cn.com/problems/largest-sum-of-averages/
// largest sum of averages
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
       size_t size = A.size();
       vector<vector<double>> dp = {size, vector<double>(K + 1, 0)};
       vector<int> sum(size + 1, 0);
       for(int i = 1; i <= size; i++){
           sum[i] = sum[i - 1] + A[i - 1];
           dp[i - 1][1] = sum[i] * 1.0 / i;
       }

       for(int i = 1; i < size; i++){
           for(int k = 2; k <= min(K, i+1); k++){
               for(int j = 0; j < i; j++){
                   dp[i][k] = max(dp[i][k], dp[j][k - 1] + (sum[i + 1] - sum[j + 1]) * 1.0 /(i - j));
               }
           }
       }
       return dp[size - 1][K];
    }
};