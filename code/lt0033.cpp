#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target){

        if(nums.empty())
            return -1;

        if(nums.size() == 1)
            return nums[0] == target ? 0 : -1;

        int rotate_index = search_rotate_index(nums);
        int l = rotate_index + 1, h = nums.size() - 1;
        if(target >= nums[0] && target <= nums[rotate_index])
        {
            h = l;
            l = 0;
        }

        while(l <= h)
        {
            int m = (l + h)/2;
            if(nums[m] > target)
                h = m - 1;
            else if(nums[m] < target)
                l = m + 1;
            else
                return nums[m];            
        }

        return -1;
    }

    int search_rotate_index(vector<int>&nums)
    {
        int l = 0, h = nums.size() - 1;

        if(nums[l] < nums[h])
            return 0;

        while(l < h)
        {
            int m = (l +  h) / 2;
            if(nums[m] > nums[m + 1])
                return m;
            else
            {
                if(nums[m] >= nums[l])
                    l = m + 1;
                else
                    h = m - 1;
            }
        }
        return 0;
    }
};