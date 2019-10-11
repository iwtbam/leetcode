class Solution {
public:
    int trailingZeroes(int n) {
        int five_num = 0;
        for(long long i = 5; i <= n; i = i * 5)
        {
            five_num += n / i;
        }
        
        return five_num;
    }
};