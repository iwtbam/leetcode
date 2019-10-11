#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max,sum;

        if(nums.size())
        {
            max = nums.at(0);
            sum = max > 0 ? max : 0;
        }

        for(int i = 1; i < nums.size();i++)
        {
            sum += nums.at(i);

            if(sum > max)
                max = sum;

            if(sum < 0)
                sum = 0;
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> iv = {-2,1,-3,4,-1,2,1,-5,4};
    int sum = s.maxSubArray(iv);
    cout << sum << endl;
    return 0;
}