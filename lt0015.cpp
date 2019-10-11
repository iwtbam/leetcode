#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define S2

#if defined(S1)

// 确定两个数, 第三个数用二分查找, 384ms

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> vec2;
        
        if(len < 3)
            return vec2;
        
        sort(nums.begin(), nums.end());
        unordered_map<int, int> record;
        vector<int> other;
        
        for(int i = 0; i < len; i++)
        {
            int val = nums.at(i);
            if(record.find(val) == record.end())
            {
                record[val] = 1;
                other.push_back(val);
            }
            else
                record[val]++;
        }
        
        len = other.size();
        
        for(int i = 0; i < len; i++)
        {
            int val1 = other.at(i);
            int j = i + 1;
            
            if(record[val1] > 1)
            {
                record[val1]--;
                j = i;
            }
            
            for(; j < len; j++)
            {
                int val2 = other.at(j);
                int val3 = -val1 - val2;
                int k = record[val2] > 1 ? j : j + 1;
                bool r = binary_search(other.begin() + k, other.end(), val3);
                if(r)
                    vec2.push_back(vector<int>{val1, val2, val3});
                
            }
        }
        
        return vec2;
    }
};


#elif defined(S2)

// 三个指针,固定一个指针, 两个指针夹逼, 注意去除, 很有意思的方法, 92ms

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> vec2;
        
        if(len < 3)
            return vec2;
        
        vector<int> other;
        sort(nums.begin(), nums.end());
        
        if(nums.front() > 0 || nums.back() < 0)
            return vec2;
        
        unordered_map<int, int> record;
    
        for(int i = 0; i < len; i++)
            record[nums[i]]++;
            
        for(int i = 0; i < len - 2; i++)
        {
            if(i == 0 || nums[i] > nums[i-1])
            {
                int l = i + 1;
                int r = len - 1;
                while(l < r)
                {
                    int s = nums[i] + nums[l] + nums[r];
                    if(s == 0)
                    {                
                        vec2.push_back(vector<int>{nums[i], nums[l], nums[r]});
                        do{
                            l++;
                            r--;
                        }
                        while(l < r && nums[l - 1] ==nums[l] && nums[r + 1] == nums[r]);
                    }
                    else if(s > 0)
                        r--;
                    else
                        l++;
                }
            }
        }
        
        return vec2;
    }
};
#endif