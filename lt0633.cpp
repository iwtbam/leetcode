// https://leetcode-cn.com/problems/sum-of-square-numbers/
// sum of square numbers
class Solution {
public:
    bool judgeSquareSum(int c) {
        int p = min(1e6, sqrt(c));

        if(c <= 1)
            return true;

        for(int i = 1; i <= p; i++){
            int j = c - i * i;

            int sj  = sqrt(j);
            
            if(j == sj * sj)
                return true;
        }

        return false;
    }
};