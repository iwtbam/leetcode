// https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
// ba shu zu pai cheng zui xiao de shu lcof
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        int size = nums.size();
        
        for(int i = 0; i < size; i++){
            strs.push_back(to_string(nums[i]));
        }

        sort(strs.begin(), strs.end(), [](const string& a, const string& b){
            return a + b < b + a;
        });

        return accumulate(strs.begin(), strs.end(), string(""));
    }
};