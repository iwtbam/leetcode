#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

#define S2

#if defined S1
//2019-08-05:13-13 暴力 不行 超时
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    
        vector<pair<long long, long long>> res = {};        
        int size = nums.size();
        
        for(int i = 0; i < size; i++)
        {
            for(int j = i + 1; j < size && j <= i + k; j++)
            {
                long long diff = abs(static_cast<long long>(nums[j]) - nums[i]);
                if(diff <= t)
                    return true;
            }
        }
        
        return false;

    }
};

#elif defined S2

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            auto upper_iter = s.lower_bound(nums[i]);
            if(upper_iter!=s.end() && *upper_iter <= nums[i] + t)
                return true;
            auto lower_iter = s.lower_bound(nums[i]);
            if(lower_iter!=s.end() && *lower_iter >= nums[i] - t)
                return true;
            
            s.insert(nums[i]);
            if(s.size() > k)
                s.erase(nums[i-k]);
        }

        return false;

    }
};

#endif


int main()
{
    set<int> s = {1,2,3,4,5,6};

    cout <<  *s.lower_bound(-1, less<int>) << endl;

    return 0;
}