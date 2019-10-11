#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> record = {};
        for(auto num : nums){
            record[num]++;
            if(record[num] > 1)
                return true;
        }
        
        return false;
    }
};