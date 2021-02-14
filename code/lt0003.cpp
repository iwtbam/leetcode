#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG
#undef DEBUG


#ifdef S1


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(!s.size())
            return 0;

        int record[256];
        memset(record, 0, sizeof(record));
        int l = 0, i = 1, ml = 0, mr = 0;
        record[s[0]] = 1;
        for(;i < s.size(); i++)
        {
            if(record[s[i]])
            {
                #ifdef DEBUG
                    cout << l << ends << i << ends << ml << ends << mr << endl;
                #endif
                if(i - l > mr - ml + 1)
                {
                    mr = i - 1; 
                    ml = l;
                }

                l = i;    
                
                memset(record, 0, sizeof(record));
                record[s[i]] = 1;
            }
            else
                record[s[i]] = 1;
        }

        if(i - l > mr - ml + 1)
            return i - l;
        // cout << ml << ends << mr << endl;

        return mr - ml + 1;
    }
};

#else
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(!s.size())
            return 0;
        
        int pos[128], len = 0;
        memset(pos, 0, sizeof(pos));
                
       for(int i = 0, j = 0; j < s.size(); j++){
           i = max(pos[s.at(j)], i);
           len = max(len, j - i + 1);
           pos[s.at(j)] = j + 1;
       }
        return len;
    }
};
#endif

int main()
{
    Solution s;
    int c = s.lengthOfLongestSubstring("abcabcbb");
    cout << c << endl;
    c = s.lengthOfLongestSubstring("bbbbb");
    cout << c << endl;
    c = s.lengthOfLongestSubstring("pwwkew");
    cout << c << endl;
    return 0;
}