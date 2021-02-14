#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        int maxk = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            if(record.find(nums[i])==record.end())
                record[nums[i]] = i;
            else
            {
                maxk = min(maxk, i - record[nums[i]]);
                record[nums[i]] = i;
            }
        }

        return maxk == INT_MAX ? 0 : maxk <= k;
    }
};