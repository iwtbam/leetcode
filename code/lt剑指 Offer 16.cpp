// https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
// shu zhi de zheng shu ci fang lcof
class Solution {
public:
    double myPow(double x, int n) {
        
        bool flag = n > 0;
        long long e = abs(static_cast<long long>(n));
        double res = 1.0;
        while(e){
            if(e & 1)
                res *= x;
            x = x * x;
            e >>= 1;
        }
        if(!flag)
            res = 1.0 / res;
        return res;
    }
};