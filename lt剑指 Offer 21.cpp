// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
// diao zheng shu zu shun xu shi qi shu wei yu ou shu qian mian lcof
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left < right){
            while(left < right && nums[right] % 2 == 0)
                right--;
            while(left < right && nums[left] % 2 == 1)
                left++;
            if(left < right){
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }

        return nums;
    }
};