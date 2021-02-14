// https://leetcode-cn.com/problems/minimum-operations-to-make-array-equal/
// minimum operations to make array equal
class Solution {
public:
    int minOperations(int n) {
        int half = n / 2;
        return n * half - half * half;
    }
};