#include <vector>

using namespace std;

class Solution{
public:
    bool search(vector<int>& nums, int target){
        
        if(nums.empty())
            return false;
        
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(target == nums[mid])
                return true;
            
            if(nums[lo] < nums[mid])
            {
                if(nums[mid] >=target && target >=nums[lo])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }else if(nums[hi] > nums[mid])
            {
                if(nums[mid] < target && target <= nums[hi])
                    lo = mid + 1;
                else 
                    hi = mid - 1;
            }
            else
            {
                if(nums[mid] == nums[lo])
                    lo++;
                else
                    hi--;
            }
        }
        
        return false;
    }
};