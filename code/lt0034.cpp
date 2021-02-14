#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define S3

#if defined(S1)

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1, -1};
        
        int left = helper(nums, target);
        int right = left;
        if(left == -1)
            return {-1, -1};

        while(left >= 0 && nums[left--] == nums[right]);
        left++;
        while(right < nums.size() && nums[left] == nums[right++]);
        right--;
        return {left, right};
    }


    int helper(vector<int>& nums, int target){
        
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high)
        {
            int mid = (low + high) /2;
            
            if(nums[mid] == target)
                return mid;

            if(nums[mid] < target)
                low = mid + 1;
            
            if(nums[mid] > target)
                high = mid - 1;
        }

        return  -1;
    }

};


#elif defined(S2)


class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        if(left == right)
            return {-1, -1};
        auto begin = nums.begin();
        return { static_cast<int>(left - begin), static_cast<int>(right - begin - 1)};
    }

};

#elif defined(S3)

// class Solution{
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         if(nums.size() == 0)
//             return {-1, -1};
//         int size = nums.size() - 1;
//         int low = 0, high = size, left = -1, right = -1;
//         while(low <= high)
//         {
//             int mid = (low + high) / 2;
            
//             if(target == nums[mid])
//             {
//                 left = mid;
//                 if(target == nums[mid] - 1)
//                     high = mid - 1;
//                 else
//                     break;
//                 continue;
//             }

//             if(target > nums[mid])
//                 low = mid + 1;
            
//             if(target < nums[mid])
//                 high = mid - 1;
//         }

//         while(low <= high)
//         {
//             int mid = (low + high) / 2;
            
//             if(target == nums[mid])
//             {
//                 right = mid;
//                 if(target == nums[mid + 1])
//                     low = mid + 1;
//                 else
//                     break;
//                 continue;
//             }

//             if(target > nums[mid])
//                 low = mid + 1;
            
//             if(target < nums[mid])
//                 high = mid - 1;
//         }

//         return {left, right};

//     }
// };

#endif

int main()
{
    return 0;
}

