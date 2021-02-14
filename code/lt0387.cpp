#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        int size = s.size();
        for(int i = 0; i < size; i++)
            count[s[i] - 'a']++;
        for(int i = 0; i < size; i++)
            if(count[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};