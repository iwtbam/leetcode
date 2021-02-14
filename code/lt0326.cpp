// https://leetcode-cn.com/problems/power-of-three/
// power of three
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};