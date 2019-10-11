// 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
// 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


#define S2

#if defined(S1)

// 暴力 112ms

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>();
    }
};
#elif defined(S2)

// 双指针 8ms

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int len = nums.size();
        vector<int> res;
        if(len < 2)
            return res;
        
        vector<pair<int, int>> new_nums;
        auto cmp = [](pair<int, int> p1, pair<int,int> p2)
        {
          return p1.first < p2.first;  
        };
        
        for(int i = 0; i < len ; i++)
            new_nums.push_back(pair<int, int>(nums[i], i));
        
        sort(new_nums.begin(), new_nums.end(), cmp);
    
            
        int l = 0;
        int r = len - 1;
        
        while(l < r)
        {
            auto p1 = new_nums[l];
            auto p2 = new_nums[r];
            
            int sum = p1.first + p2.first;
            if(sum == target)
            {
                if(p1.second < p2.second)
                {
                    res.push_back(p1.second);
                    res.push_back(p2.second);
                }
                else
                {
                    res.push_back(p2.second);
                    res.push_back(p1.second);
                }
                return res;
            }
            else if(sum > target)
                r--;
            else
                l++;
            
        }
        return res;
    }
};


#endif

int main()
{
    return 0;
}