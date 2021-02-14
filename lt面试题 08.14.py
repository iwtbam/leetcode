# https://leetcode-cn.com/problems/boolean-evaluation-lcci/ 
# boolean evaluation lcci 
class Solution:
    def countEval(self, s: str, result: int) -> int:
        n = len(s)
        dp = [[[0, 0] for _ in range(n)] for _ in range(n)]

        for i in range(n):
            c = s[i]
            if c == '0':
                dp[i][i][0] = 1
            if c == '1':
                dp[i][i][1] = 1

        for l in range(2, n + 1):
            for i in range(0, n - l + 1):
                j = i + l - 1
                for k in range(i + 1, j):
                    if s[k] in ['0', '1']:
                        continue
                    
                    if s[k] == '|':
                        dp[i][j][0] += dp[i][k - 1][0] * dp[k+1][j][0]
                        dp[i][j][1] += dp[i][k - 1][0] * dp[k+1][j][1] + dp[i][k - 1][1] * dp[k+1][j][0] + dp[i][k - 1][1] * dp[k+1][j][1]
                    
                    if s[k] == '&':
                        dp[i][j][0] += dp[i][k - 1][0] * dp[k+1][j][1] + dp[i][k - 1][1] * dp[k+1][j][0] + dp[i][k - 1][0] * dp[k+1][j][0]
                        dp[i][j][1] += dp[i][k - 1][1] * dp[k+1][j][1]
                    
                    if s[k] == '^':
                        dp[i][j][0] += dp[i][k - 1][0] * dp[k+1][j][0] + dp[i][k - 1][1] * dp[k+1][j][1]
                        dp[i][j][1] += dp[i][k - 1][0] * dp[k+1][j][1] + dp[i][k - 1][1] * dp[k+1][j][0] 
        return dp[0][n - 1][result]