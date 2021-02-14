//2019-07-08:16-42 样例真恶心


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        long long x = static_cast<long long>(n);
        return (x & (x-1)) == 0;
    }
};