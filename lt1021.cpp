// https://leetcode-cn.com/problems/remove-outermost-parentheses/
// remove outermost parentheses
class Solution {
public:
    string removeOuterParentheses(string S) {
        int leftnum = 0, rightnum = 0;
        string res = {};
        int size = S.size();
        int left = 0;
        for(int i = 0; i < size; i++){
            if(S[i] == ')')
                leftnum++;
            if(S[i] == '(')
                rightnum++;
            
            if(leftnum == rightnum){
                int len = i - left + 1;
                res += S.substr(left + 1, len - 2);
                leftnum = 0;
                rightnum = 0;
                left = i + 1;
            }
        }
        
        return res;
    }
};