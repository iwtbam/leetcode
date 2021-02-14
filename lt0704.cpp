// https://leetcode-cn.com/problems/binary-search/
// binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) >> 1;
            
            // cout << 

            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }
};