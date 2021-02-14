// https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
// fan zhuan dan ci shun xu lcof
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res;
        string temp;
        while(ss >> temp){
            res = temp + " " + res;
        }
        return res.substr(0, res.size() - 1);
    }
};