#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        int r = gcd(x, y);
        if(x+y<z)
            return false;
        return z % r == 0;        
    }

    inline int gcd(int a, int b)
    {
        if(a == 0)
            return b;
        int r = b % a;
        return gcd(r, a);
    }
};