class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0)
            return 1;
        
        if(n == 1)
            return 10;

        long long cur = 10, mul = 9;

        for(int i = 0; i < n - 1; i++)
        {
            mul *= (9 - i);
            cur = mul + cur;
        }

        return cur;
    }
};