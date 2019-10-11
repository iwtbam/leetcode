#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2)
            return nums;

        int res = nums[0];

        for(int i = 1; i < nums.size(); i++)
            res ^= nums[i];

        int bit = 1;

        while((bit & res) == 0)
            bit <<=1;
        
        int a = 0;

        for(int i = 0; i < nums.size();i++)
        {
            if(bit & nums[i])
                a = a ^ nums[i];
        }

        return { a, a ^ res };
    }
};