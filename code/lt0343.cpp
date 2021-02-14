#include <vector>
#include <cmath>

using namespace std;

//2019-08-04:20:00 这就是一个数学问题,然而我是猜的。

class Solution {
public:
    int integerBreak(int n) {
        int maxv = 1;
        int half = n / 2;
        
        for(int i = 2; i <= half;i++)
        {
            int n1 = n / 2;
            int n2 = n % 2;
            maxv = max(maxv, static_cast<int>(pow(i, n1 - n2) * pow(i + 1, n2)));
        }      

        return maxv;
    }
};