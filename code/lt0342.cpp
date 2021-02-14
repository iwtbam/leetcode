class Solution {
public:
    bool isPowerOfFour(int num) {
        long long x = static_cast<long  long>(num);
        int mask = 0x55555555;
        return num > 0 && (x & (x - 1)) == 0 && (x & mask);
    }
};