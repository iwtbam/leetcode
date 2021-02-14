// https://leetcode-cn.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
// decrypt string from alphabet to integer mapping
class Solution {
public:
    string freqAlphabets(string s) {
        int num = 0;
        int p = 0;
        int size = s.size();
        string res = {};
        while(p < size){
            char c = s[p];
            if(c >= '3' || (p + 2 < size && s[p + 2] != '#') || (p + 2 >= size)){
                res.push_back(c - '0' + 'a' - 1);
                p += 1;
                continue;
            }
            
            num = ((c - '0') * 10 + s[p + 1] - '0') - 1;
            res.push_back(num + 'a');
            p += 3;
        }
        
        return res;
    }
};