#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        uint8_t mask = 0xC0;
        uint8_t header_mask[4] = {0xF8, 0xF0, 0xE0, 0x80};
        uint8_t header_val[4] = {0xF0, 0xE0, 0xC0, 0x00};
        for(int i = 0; i < data.size(); i++){
            int len = -1;
            for(int j = 0; j < 3; j++){
                if((header_mask[j] & data[i])==header_val[j]){
                    len = 3 - j;
                    break;
                }
            }

            if(len == -1 && (header_mask[3] & data[i]) == header_val[3])    
                len = 0;
            
            if(len == -1)
                return false;
            
            for(int k = i + 1; k <=  i + len; k++)
            {
                if(k >= data.size())
                    return false;
                
                if((mask & data[k]) != 0x80)
                    return false;
            }
            i = i + len;
        }

        return true;
    }
};