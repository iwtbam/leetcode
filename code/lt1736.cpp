// https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits/
// latest time by replacing hidden digits
class Solution {
public:
    string maximumTime(string s) {
        
        int nums[5] = {2, 3, 0, 5, 9};
        for(int i = 0; i < 5; i++){
            if(i == 2)
                continue;
            
            if(s[i] == '?'){
                if(i == 1){
                    s[i] = s[0] < '2' ? '9' : '3';
                }else if(i == 0){
                    s[i] = (s[1] != '?' && s[1] > '3') ? '1' : '2';
                }else{
                    s[i] = nums[i] + '0';
                }
            }
        }
        return s;
    }
};