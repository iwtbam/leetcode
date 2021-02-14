// https://leetcode-cn.com/problems/minimum-length-of-string-after-deleting-similar-ends/
// minimum length of string after deleting similar ends
class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() - 1;
        int op = 0;
        
        while(l < r && s[l] == s[r]){
            op++;
            char c = s[l];
            while(l + 1 < r && s[l + 1] == c)
                l++;
            while(l < r - 1 && s[r - 1] == c)
                r--;
            
            l = l + 1;
            r = r - 1;
        }
        
        if(l > r)
            return 0;
        
        return r - l + 1;
    }
};