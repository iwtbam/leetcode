#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findPeakElement(vector<int>& nums){
        int size = nums.size();
        
        if(size == 0)
            return -1;

        if(size == 1)
            return 0;

        if(nums[0] > nums[1])
            return 0;

        if(nums[size - 1] > nums[size - 2])
            return size-1;


        int l = 0, h = size - 2;

        while(l <= h)
        {
            int m = (l + h) / 2;
            if(nums[m] > nums[m+1])
                h = m - 1;
            else
                l = m + 1;
        }

        return l;
    }
};