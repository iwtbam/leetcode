// https://leetcode-cn.com/problems/largest-substring-between-two-equal-characters/
// largest substring between two equal characters
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int pos[26] = {0};
        int ans = -1;
        size_t n = s.size();
        for(int i = 0; i < n; i++){
            if(pos[s[i] - 'a'] > 0){
                ans = max(ans, i - pos[s[i] - 'a']);
            }else{
                pos[s[i] - 'a'] = i + 1;
            }
        }
        
        return ans;
    }
};