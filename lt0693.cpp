#include <cstdint>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        uint32_t mask[2] = {0x55555555, 0xaaaaaaaa};
        uint32_t bit = 1;
        for(int i = 31; i >=0; i--){
            if((bit << i)& n){
                bit <<= i;
                break;
            }
        }
        
        bit = (bit << 1) - 1;
        
        return ((n ^ mask[0]) & bit) == 0 || ((n ^ mask[1]) & bit)== 0;
    }
};