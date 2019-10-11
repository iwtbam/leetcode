#include <cmath>

using namespace std;
//2019-08-04:18-59 牛顿迭代法

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long x0 = num;
        while(x0 * x0 > num)
        {
            x0 = (pow(x0, 2) + num) / (2 * x0);
        }

        return x0 * x0 == num;
    }
};