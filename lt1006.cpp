// https://leetcode-cn.com/problems/clumsy-factorial/
// clumsy factorial
class Solution {
public:
    int clumsy(int N) {
        if(N <= 2)
            return N;
        if(N == 3)
            return 6;
        if(N == 4)
            return 7;
        return N * 2 - 4 * (N / 4) + 2 - clumsy(N - N / 4 * 4);
    }
};