#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int>& nums){

        int size = nums.size();
        int l = 0, h = size;

        while(l < h)
        {
            int mid = (l + h) / 2;

            if(mid + 1 < size && nums[mid] < nums[mid+1])
                return nums[mid+1];

            if(nums[mid] > nums[0])
                l = mid + 1;
            else
                h = mid - 1;
        }
        return nums[l];
    }
};
