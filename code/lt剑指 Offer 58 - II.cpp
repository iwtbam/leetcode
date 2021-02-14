// https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
// zuo xuan zhuan zi fu chuan lcof
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(n >= s.size())
            return s;
        return s.substr(n) + s.substr(0, n);
    }
};