class Solution {
public:
    int findComplement(int num) {
        
        unsigned mask = 1 << 31;
        
        while((mask & num) == 0)
            mask = mask >> 1;
        
        mask = (mask << 1) - 1;
        
        return num ^ mask;
    }
};