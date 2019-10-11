#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 双指针 无剪枝 24ms

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int len = nums.size();
        vector<vector<int>> res;
        if(len < 4)
            return res;
        
        sort(nums.begin(), nums.end());
        
        
        for(int i = 0; i < len - 3; i++)
        {
            int val1 = nums.at(i);
            
            if(i!=0 && val1 == nums.at(i-1))
                continue;
            
            for(int j = i + 1; j < len-2; j++)
            {
                int val2 = nums.at(j);
                
                if(j !=i+1 && val2 == nums.at(j-1))
                    continue;
                    
                int l = j + 1;
                int r = len - 1;
                
                while(l < r)
                {
                    int val3 = nums.at(l);
                    int val4 = nums.at(r);
                    
                    int sum = val1 + val2 + val3 + val4;
                    if(sum == target)
                    {
                        res.push_back(vector<int>{val1, val2, val3, val4});
                        l++, r--;
                        while(l < r && nums[l]==nums[l-1] && nums[r] == nums[r+1])
                            l++, r--;
                    }

                    else if (sum < target)
                        l++;
                    else 
                        r--;
                }
            }
        }
        return res;
    }
};