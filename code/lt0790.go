// https://leetcode-cn.com/problems/domino-and-tromino-tiling/
// domino and tromino tiling
func numTilings(N int) int {

	const MOD int = 1000_000_000 + 7

	dp := [4]int{1, 0, 0, 0}

	for i := 0; i < N; i++ {
		ndp := [4]int{0, 0, 0, 0}
		ndp[0] = (dp[0] + dp[3]) % MOD
		ndp[1] = (dp[0] + dp[2]) % MOD
		ndp[2] = (dp[0] + dp[1]) % MOD
		ndp[3] = ((dp[0] + dp[1]) % MOD + dp[2]) % MOD
		dp = ndp
	}

    return dp[0]
}