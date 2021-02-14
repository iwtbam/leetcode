// https://leetcode-cn.com/problems/string-to-url-lcci/
// string to url lcci
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int tail = S.size() - 1;
        int cur = length - 1;
        while(cur >= 0){
            if(S[cur] == ' '){
                S[tail--] = '0';
                S[tail--] = '2';
                S[tail--] = '%';
            }else{
                S[tail--] = S[cur];
            }
            cur--;
        }
        return S.substr(tail + 1);
    }
};