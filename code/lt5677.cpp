// https://leetcode-cn.com/problems/count-number-of-homogenous-substrings/
// count number of homogenous substrings
class Solution {
public:
    int countHomogenous(string s) {
        int l = 0, r = 0, size = s.size();
        long long count = 1;
        long long ans = 0;
        int mod = 1e9 + 7;
        for(int i = 1; i <= size; i++){
            if(i != size && s[i] == s[i - 1]){
                count++;
            }else{
                ans = (ans + count * (count + 1) / 2) % mod;
                count = 1;
            }
        }
        
        return ans;
    }
};