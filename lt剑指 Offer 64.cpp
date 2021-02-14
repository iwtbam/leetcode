// https://leetcode-cn.com/problems/qiu-12n-lcof/
// qiu 12n lcof
class Solution {
public:
    int sumNums(int n) {
        if(n <= 1)
            return n;
        return n + sumNums(n - 1);
    }
};