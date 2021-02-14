#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
            return false;

        int r1[26] = {0};
        int r2[26] = {0};

        size_t size= s.size();
        for(int i = 0; i < size; i++)
        {
            r1[s[i]-'a']++;
            r2[t[i]-'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(r1[i]!=r2[i])
                return false;
        }

        return true;   
    }
};