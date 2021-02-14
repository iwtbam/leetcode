// https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
// shu zu zhong chu xian ci shu chao guo yi ban de shu zi lcof
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int size = nums.size(), num = nums[0], vote = 1, total = 1;
        for(int i = 1; i < size; i++){
            total = total + 1;
            if(nums[i] == num){
                vote = vote + 1;
            }else{
                if(vote * 2 < total){
                    vote = 1;
                    total = 1;
                    num = nums[i];
                }
            }
        }

        return num;
    }
};