// https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/
// jian sheng zi ii lcof
class Solution {
public:

    const static int MOD = 1000000007;

    long long ipow(long long num, int e){
        long long res = 1;
        while(e){
            if(e & 1){
                res *= num;
                res = res % MOD;
            }
            e >>= 1;
            num = (num * num) % MOD;
        }
        return res;
    }

    int cuttingRope(int n) {
        if(n <= 3)
            return n - 1;
        int avg = n / 3;
        int mod = n % 3;
        long long res = 0;
        if(mod == 0)
            res = ipow(3, avg);
        else if(mod == 1){
            res = (ipow(3, avg - 1) * 4);
        }else{
            res = (ipow(3, avg) * 2);
        }
        return res % MOD;      
    }
};