// https://leetcode-cn.com/problems/string-rotation-lcci/
// string rotation lcci
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        string s3 = s1 + s1;
        return s3.find(s2) != string::npos;
    }
};