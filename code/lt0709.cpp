// https://leetcode-cn.com/problems/to-lower-case/
// to lower case
class Solution {
public:
    string toLowerCase(string str) {
        size_t size = str.size();
        for(int i = 0; i < size; i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] - 'A' + 'a';
            }
        }

        return str;
    }
};