class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums = {nums.begin(), nums.end()};
        sort(sorted_nums.begin(), sorted_nums.end());
        int size = nums.size();
        int left = 0, right = size - 1;
        while(left < size && nums[left] == sorted_nums[left])
            left++;
        if(left == size)
            return 0;
        while(right >= 0  && nums[right] == sorted_nums[right]){
            right--;
        }        
        return right - left + 1;
    }
};