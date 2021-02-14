// https://leetcode-cn.com/problems/number-of-paths-with-max-score/
// number of paths with max score
class Solution {
    public int[] pathsWithMaxScore(List<String> board) {
        int rows = board.size();
        int cols = board.get(0).length();
        
        long dp[][][] = new long[rows][cols][2];
        
        dp[rows - 1][cols - 1] = new long[]{0, 1};
        
        for(int i = rows - 1; i >= 0; i--){
            for(int j = cols - 1; j>=0; j--){
                if(i == rows - 1 &&  j == cols - 1)
                    continue;
                
                
                  char c = board.get(i).charAt(j); 
                
                if(c == 'X')
                    continue;
                
                long cur = 0;
              
                if(c != 'E')
                    cur = c - '0';
                
                long right[]  = j + 1 < cols ? dp[i][j + 1] : new long[]{0, 0};
                long bottom[] = i + 1 < rows ? dp[i + 1][j] : new long[]{0, 0};
                long dia[]    = i + 1 < rows && j + 1 < cols ? dp[i + 1][j + 1] : new long[]{0, 0};
                
              
                if(right[1] !=0 && right[0] + cur >= dp[i][j][0]){
                    dp[i][j][0] = right[0] + cur;
                    if(right[0] + cur == dp[i][j][0])
                        dp[i][j][1] += right[1];
                    else
                        dp[i][j][1] = right[1];
                }
                
                if(dia[1]!=0 && dia[0] + cur >= dp[i][j][0]){
                    if(dia[0] + cur == dp[i][j][0])
                        dp[i][j][1] += dia[1];
                    else
                        dp[i][j][1] = dia[1];
                    dp[i][j][0] = dia[0] + cur;

                }
             
                
                if(bottom[1]!=0 && bottom[0] + cur >= dp[i][j][0]){
                    if(bottom[0] + cur == dp[i][j][0])
                        dp[i][j][1] += bottom[1];
                    else
                        dp[i][j][1] = bottom[1];
                    dp[i][j][0] = bottom[0] + cur;

                }
                
                dp[i][j][1] %= MOD;
                
                
        
            }
        }
        
        
        return new int[]{ (int)dp[0][0][0] % MOD, (int)dp[0][0][1] % MOD};
    }
    
    private int MOD = (int)Math.pow(10, 9) + 7;
}