// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
// zai pai xu shu zu zhong cha zhao shu zi lcof
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return upper_bound(nums, target) - lower_bound(nums, target);
    }


    int lower_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target){
                right = mid;
            }else{
                left  = mid + 1;
            }
        }

        return left;
    }

    int upper_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > target){
                right = mid;
            }else{
                left  = mid + 1;
            }
        }

        return left;
    }
};