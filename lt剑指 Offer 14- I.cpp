// https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
// jian sheng zi lcof
class Solution {
public:

    long long ipow(long long base, int e){
        long long res = 1;
        while(e){
            if(e & 1){
                res *= base;
            }
            e >>= 1;
            base *= base;
        }
        return res;
    }
    int cuttingRope(int n) {
        if(n <= 3)
            return n - 1;
        int avg = n / 3;
        int mod = n % 3;
        long long res = 0;
        if(mod == 0){
            res = ipow(3, avg);
        }else if(mod == 1){
            res = ipow(3, avg - 1) * 4;
        }else{
            res = ipow(3, avg) * 2;
        }
        return res;
    }
};