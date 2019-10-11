#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size() <= 1)
            return nums.size();
        
        if(nums.size() == 2)
            return static_cast<int>(nums[0] != nums[1]) + 1;
        
        
        int size = nums.size(), pre = 0;
        int i = 1;
        while(pre == 0 && i < size){
            pre = nums[i] - nums[i-1];
            i++;
        }
        
        if(pre == 0)
            return 1;
        
        int l = 2;
        int is_not_zero_flag = pre;
        
        for(int j = i; j < size; j++)
        {
            int cur = nums[j] - nums[j-1];
            if(cur * pre < 0)
                l++;
            
            if(pre == 0 && is_not_zero_flag * cur < 0)
                l++;
                
            pre  = cur;
            if(pre)
                is_not_zero_flag = pre;
        }
        
        
        return l;
    }
};