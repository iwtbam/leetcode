#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int last_pos = size - 1;
        for(int i = size - 1; i >= 0; i--){
            if(nums[i] + i >= last_pos)
                last_pos = i;
        }
        
        return last_pos == 0;
    }
};