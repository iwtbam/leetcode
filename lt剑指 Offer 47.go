// https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
// li wu de zui da jie zhi lcof
func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func maxValue(grid [][]int) int {

    rows, cols := len(grid), len(grid[0])
    dp := make([][]int, rows);
    
    for i := 0; i < rows; i++ {
        dp[i] = make([]int, cols);    
    }

    dp[0][0] = grid[0][0]

    for i := 1; i < rows; i++ {
        dp[i][0] = dp[i - 1][0] + grid[i][0];        
    }

    for i := 1; i < cols; i++ {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    for i := 1; i < rows; i++ {
        for j := 1; j < cols; j++{
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[rows - 1][cols - 1]
}