#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q;
        unordered_set<int> record;
        
        for(int i = 0; i < nums.size(); i++)
            record.insert(nums[i]);
        
        int max_v = INT_MIN;
        
        if(record.size() < 3)
        {
            for(auto num:record)
            {
                max_v = max(max_v, num);
            }
            
            return max_v;
        }
        
        int i = 0;
        
        for(auto num: record)
        {
            q.push(num);
            if(i >= 3)
                q.pop();
            i++;

        }
        
        
        return q.top();
    }
};