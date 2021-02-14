// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
// fei bo na qi shu lie lcof
class Solution {
public:
    const static int MOD = 1000000007;
    int fib(int n) {
        if(n <= 1)
            return n;
        
        int a = 0, b = 1;
        for(int i = 2; i <= n; i++){
            if(i % 2 == 0)
                a = (a + b) % MOD;
            else
                b = (a + b) % MOD;
            
        }

        return n % 2 == 0 ? a : b;

    }
};