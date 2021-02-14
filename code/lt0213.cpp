#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.empty())
            return 0;

        if(nums.size()==1)
            return nums[0];

        if(nums.size()==2)
            return max(nums[0], nums[1]);

        vector<int> dp1 = {nums.begin(), nums.end() - 1};
        vector<int> dp2 = {nums.begin() + 1, nums.end()};

        dp1[1] = max(dp1[1], dp1[0]);
        dp2[1] = max(dp2[1], dp2[0]);

        int size = dp1.size();

        for(int i = 2; i < size;i++)
        {
            dp1[i] = max(dp1[i-1], dp1[i-2] + dp1[i]);
            dp2[i] = max(dp2[i-1], dp2[i-2] + dp2[i]);
        } 

        return max(dp1[size-1], dp2[size - 1]);
    }
};