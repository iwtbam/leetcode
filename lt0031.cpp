#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

#if defined(o1)
class Solution {
public:

    void swap(int& a, int& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        pair<int, int> record;
        int pre_pos = -1;
        for(int i = size - 1; i > 0; i--)
        {
            for(int j = i - 1; j >=0;j++)
            {
                if(nums[i] > nums[j])
                {
                    if(j > pre_pos)
                    {
                        record = {j, i};
                        pre_pos = j;
                    }
                    break;
                }
            }
        }

        if(pre_pos == -1)
            sort(nums.begin(), nums.end());
        else
        {
            swap(nums[record.first], nums[record.second]);
            sort(nums.begin() + record.first + 1, nums.end());
        }
    }
};

#elif defined(o2)

#endif