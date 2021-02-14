#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record;
        for(auto num:nums)
            record.insert(num);

        int len = 0;
        for(auto num:record)
        {
            if(record.find(num - 1)==record.end())
            {
            
                int curlen = 1;
                while(record.find(num+curlen)!=record.end())
                    curlen++;
                len = max(len, curlen);
            }
        }

        return len;        
    }
    
};