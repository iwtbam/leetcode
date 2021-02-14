#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int d = INT_MAX;
        int close = 0;
        
        int len = nums.size();
        
        for(int i = 0; i < len - 2; i++)
        {
            int l = i + 1;
            int r = len - 1;
            
            int val1 = nums.at(i);
            
            while(l < r)
            {
                int val2 = nums.at(l);
                int val3 = nums.at(r);
                int sum = val1 + val2 + val3;
                if(sum == target)
                    return target;
                else
                {
                    if(abs(sum - target) < d)
                    {
                        d = abs(sum - target);
                        close = sum;
                    }
                    
                    if(sum < target)
                        l++;
                    else 
                        r--;
                }            
                
            }
        }
        return close;
    }
};