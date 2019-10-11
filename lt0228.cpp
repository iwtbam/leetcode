#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        if(nums.empty())
            return {};
        
        vector<pair<int, int>> record = {{nums[0], nums[0]}};
        for(int i = 1; i < nums.size(); i++){
            if(record.back().second == nums[i] - 1){
                record.back().second = nums[i];
            }else{
                record.emplace_back(nums[i], nums[i]);
            }
        }
        vector<string> res = {};
        
        for(auto& p : record){
            if(p.first != p.second)
                res.push_back(to_string(p.first) + "->" + to_string(p.second));
            else
                res.push_back(to_string(p.first));
        }
        
        return res;
    }
    
};