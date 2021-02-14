#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        auto cmp = [](int a, int b){
            string s1 = to_string(a);
            string s2 = to_string(b);
            return (s1 + s2) > (s2 + s1);      
        };

        sort(nums.begin(), nums.end(), cmp);

        string res = {};
        for(auto num:nums)
            res += to_string(num);
        
        if(res.size() && res[0]=='0')
            return "0";

        return res;
        
    }
};