// https://leetcode-cn.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// minimum insertions to balance a parentheses string
class Solution {
public:
    int minInsertions(string s) {
        int l = 0, r = 0;        
        size_t size = s.size();
        string new_s = {};
        int ans = 0;
        for(int i = 0; i < size; i++){
            if(s[i] == '(')
                l++;
            if(s[i] == ')')
                r++;
            
            if(r % 2 == 1){
                
                if(i == size - 1 || s[i + 1] != ')'){
                    r++;
                    ans++;
                }
            }
            
            if(r == l * 2  + 2){
                l++;
                ans++;
            }
            
            if(r == l * 2){
                l = 0;
                r = 0;
            }
        }
        
        ans += l * 2 - r;
        
        return ans;
    }
};