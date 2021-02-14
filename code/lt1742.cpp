// https://leetcode-cn.com/problems/maximum-number-of-balls-in-a-box/
// maximum number of balls in a box
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int nums[50] = {0};
        
        for(int i = lowLimit; i <= highLimit; i++){
            int sum = 0;
            int num = i;
            while(num > 0){
                sum += num % 10;
                num = num / 10;
            }
            
            nums[sum] += 1; 
        }
        return *max_element(nums, nums + 50);
    }
};