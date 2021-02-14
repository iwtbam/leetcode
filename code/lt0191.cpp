#include <cstdint>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bit = 1;
        int num = 0;
        for(int i = 0; i < 32; i++){
            if(n & (bit << i))
                num++;
        }
        return num;
    }
};