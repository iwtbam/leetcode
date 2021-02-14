#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
       
        int size = s.size();
        int l = 0, i = size - 1;
        while(i >=0 && s[i]==' ')
            i--;
        for(; i >= 0 && s[i]!=' '; i--)
            l++;
        return l;
    }
};