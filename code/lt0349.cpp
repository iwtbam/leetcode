#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> record;
        set<int> res = {};
        for(auto num:nums1)
            record[num] = 1;
        for(auto num:nums2)
            if(record[num])
                res.insert(num);
        return {res.begin(), res.end()};
                
    }
};