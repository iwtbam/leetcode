#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor){
        
        int sign = -1;
        
        if((dividend > 0 && divisor >0) || (dividend < 0) && (divisor < 0))
            sign = 1;
        
        long long dividend_l = abs((long long)dividend);
        long long divisor_l = abs((long long)divisor);
        
      
        long long res = 0;
        while(dividend_l >= divisor_l)
        {
            long long t = 1;
            long long d = divisor_l;
            while(d <= dividend_l)
            {
                t = t << 1;
                d = d << 1;
            }
            res = res | (t >> 1);
            dividend_l = dividend_l -(d >> 1);
        }
        
        if(res > INT_MAX)
            return INT_MAX;
        return res * sign;
    }
};