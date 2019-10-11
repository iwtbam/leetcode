#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> record;
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++)
            record[nums1[i]]++;
        
        for(int i = 0; i < nums2.size(); i++)
        {
            if(record[nums2[i]])   
            {
                res.push_back(nums2[i]);
                record[nums2[i]]--;
            }
        }
        
        return res;
    }
};