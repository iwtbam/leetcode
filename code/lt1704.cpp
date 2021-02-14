// https://leetcode-cn.com/problems/determine-if-string-halves-are-alike/
// determine if string halves are alike
class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int record[26] = {0};
        record['a' - 'a'] = 1;
        record['e' - 'a'] = 1;
        record['o' - 'a'] = 1;
        record['i' - 'a'] = 1;
        record['u' - 'a'] = 1;
        
        size_t size = s.size();
        size_t half = size / 2;
        int nums[2] = {0, 0};
        
        for(int i = 0; i < size; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                nums[i / half] += record[s[i] - 'a'];
            }else{
                nums[i / half] += record[s[i] - 'A'];
            }
        }
        
        return nums[0] == nums[1];
    }
};