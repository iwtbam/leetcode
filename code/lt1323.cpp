// https://leetcode-cn.com/problems/maximum-69-number/
// maximum 69 number
class Solution {
public:
    int maximum69Number (int num) {
        vector<int> nums = {};
        while(num){
            nums.push_back(num % 10);
            num /= 10;
        }
        
        int size = nums.size();
        int res = 0, count = 1;
        for(int i = size - 1; i >= 0; i--){
            if(nums[i] == 6 && count == 1){
                count = 0;
                nums[i] = 9;
            }
            
            res = res * 10 + nums[i];
        }
        
        return res;
    }
};