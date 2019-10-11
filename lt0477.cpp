#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int size = nums.size();
        
        for(int i = 0; i < 32; i++){
            int p = 0;
            uint32_t mask = 1 << i ;
            for(auto num:nums){
                if(num & mask)
                    p++;
            }

            total += p * (size - p);
        }
        
        return total;
    }
};