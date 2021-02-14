// https://leetcode-cn.com/problems/number-of-substrings-with-only-1s/
// number of substrings with only 1s
class Solution {
public:
    int numSub(string s) {
        long long len = 0, size = s.size(), res = 0;
        const int MOD = pow(10, 9) + 7;
        
        for(int i = 0; i < size; i++){
            if(s[i] == '1'){
                len++;
            }else{
                res = (res + len * (len + 1L) / 2) % MOD;
                len = 0;
            }
        }
        
        res = (res + len * (len + 1) / 2) % MOD;
        return res;
    }
};