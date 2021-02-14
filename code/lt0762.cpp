#include <vector>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        
        int total = 0;
        for(int i = L; i<=R; i++){
            int bit_len = 0;
            int num = i;
            while(num){
                num = num & (num - 1);
                bit_len++;
            }
            if(record[bit_len])
                total++;
        }
        
        return total;
    }
    
private:
    int record[33] = {
        0, 0, 1, 1, 0, 1,
           0, 1, 0, 0, 0,
           1, 0, 1, 0, 0,
           0, 1, 0, 1, 0,
           0, 0, 1, 0, 0,
           0, 0, 0, 1, 0,
           1, 0
        };
};