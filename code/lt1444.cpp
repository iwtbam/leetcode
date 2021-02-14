// https://leetcode-cn.com/problems/number-of-ways-of-cutting-a-pizza/
// number of ways of cutting a pizza
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        rows = pizza.size();
        cols = pizza[0].size();
        vector<vector<int>> apples = build(pizza);
        vector<vector<vector<int>>> dp = {rows, {cols, vector<int>(k, 0)}};

        const static int MOD = pow(10, 9) + 7;

        if(getApple(apples, 0, 0, rows - 1, cols - 1) > 0)
            dp[0][0][0] = 1;

        for(int t = 1; t < k; t++){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    
                    if(getApple(apples, i, j, rows - 1, cols - 1) == 0){
                        continue;
                    }

                    for(int pi = 0; pi < i; pi++){
                        if(getApple(apples, pi, j, i - 1, cols - 1) == 0)
                            continue;
                        dp[i][j][t] = (dp[i][j][t] + dp[pi][j][t - 1]) % MOD;
                    }

                    for(int pj = 0; pj < j; pj++){
                        if(getApple(apples, i, pj, rows - 1, j - 1) == 0)
                            continue;
                        dp[i][j][t] = (dp[i][j][t] + dp[i][pj][t - 1]) % MOD;
                    }
                }
            }
        }

        int sum = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                sum = (sum + dp[i][j][k - 1]) % MOD;
            }
        }

        return sum;
    }

    vector<vector<int>> build(vector<string>& pizza){
        vector<vector<int>> apples = {rows + 1, vector<int>(cols + 1, 0)};
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                int count = pizza[i - 1][j - 1] == 'A' ? 1 : 0;
                apples[i][j] = apples[i - 1][j] + apples[i][j - 1] - apples[i - 1][j - 1] + count;
            }
        }
        return apples;
    }

    inline int getApple(vector<vector<int>>& apples, int lr, int lc, int rr, int rc){
        return apples[rr + 1][rc + 1] - apples[rr + 1][lc] - apples[lr][rc + 1] + apples[lr][lc]; 
    }

private:
    size_t rows, cols;
};