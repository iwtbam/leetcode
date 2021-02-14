#include <cmath>

using namespace std;

//2019-08-04:19-10 快速幂 卡边界真恶心 算了我菜

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(x == 0)
            return 0;
        
        if(x == 1)
            return 1;
        
        int flag = n > 0 ? 1:0;
        double ans = 1;
        
        long long base = abs(static_cast<long long>(n));

        while(base)
        {
            if(base & 1)
                ans *=x;
            x*=x;
            base >>= 1;
        }      

        return flag ? ans : 1 / ans;            
    }
};