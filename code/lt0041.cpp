#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//2019-06-09: 出乎意料的简单了

class Solution {
public:
    int firstMissingPositive(vector<int>& nums){
        
        if(nums.empty())
            return 1;
        
        auto min_iter = min_element(nums.begin(), nums.end());
        auto max_iter = max_element(nums.begin(), nums.end());

        if(*min_iter > 1)
            return 1;
        
        sort(nums.begin(), nums.end());
        int len = nums.size(), i;
        
        for(i = 0; i < len && nums[i] <=0; i++);
    
        if(i == len || nums[i] > 1)
            return 1;

        int pre = nums[i];
        int cur = pre;
        
        for(i = i + 1; i < len; i++)
        {
            pre = cur;
            cur = nums[i];
            if(cur - pre > 1)
                return pre + 1;
        }
        
        if(cur == pre + 1)
            return cur + 1;
        return pre + 1;
    }
};