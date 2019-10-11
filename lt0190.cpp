#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t bit = 1;
        uint32_t res = res | (bit & n);
        for(int i = 1; i < 32; i++)
            res = (res << 1 |(n & (bit << i)) >> i) ;
        return res;
    }
};