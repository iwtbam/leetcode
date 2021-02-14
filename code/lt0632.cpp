#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        if(nums.empty())
            return {};

        int l = 0, r = INT_MAX;

        int size = nums.size();
        vector<int> ids(size, 0);
        vector<int> vals(size, 0);

        for(int i = 0; i < size; i++)
            vals[i] = nums[i][ids[i]];
       
        while(true)
        {
            
            int ml = *min_element(vals.begin(), vals.end());
            int mr = *max_element(vals.begin(), vals.end());
            
            if(mr - ml < (r - l))
            {
                r = mr;
                l = ml;
               
            }

            for(int i = 0; i < size; i++)
            {
                
                while(ml == nums[i][ids[i]]){
                    ids[i]++;
                    if(ids[i]>=nums[i].size())
                        return {l, r};
                   
                    vals[i] = nums[i][ids[i]];
                }
            }
        }

        return {l, r};
    }
};