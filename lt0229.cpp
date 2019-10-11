#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x = 0, y = 0, cx = 0, cy = 0;

        for(auto num : nums){
            if((cx == 0 || num == x) && y!=num){
                x = num, cx++;
            }else if(cy == 0 || num == y){
                y = num , cy++;
            }else{
                --cx, --cy;
            }
        }

        int count = 0;

        for(auto num : nums){
            if(num == x)
                count++;
        }

        vector<int> res = {};

        if(count > nums.size() / 3)
            res.push_back(x);

        count = 0;

        for(auto num : nums){
            if(num == y)
                count++;
        }
        
        if(x == y)
            return res;

        if(count > nums.size() / 3)
            res.push_back(y);

        return res;
    }
};