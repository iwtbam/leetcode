class Solution {
public:
    int mySqrt(int x) {
        long long x0 = x;
        while(x0 * x0 > x)
        {
            x0 = (x0 * x0 + x) / (2 * x0);
        }
        
        return x0;
    }
};