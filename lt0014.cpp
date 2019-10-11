#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
        
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        
        if(len == 0)
            return "";
        
        int count[26];
        int i = 0;
        bool is_continue = true;
        memset(count, 0, sizeof(count));
        
        for(;is_continue; i++)
        {
            char c = 'a';
            
            for(int j = 0; j < len; j++)
            {
                string s = strs[j];
                
                if(s.size() >= i + 1)
                {
                    c = s[i];
                    count[c - 'a']++;
                    if(count[c - 'a'] != j + 1)
                        is_continue = false;       
                }
                else
                    is_continue = false;
                
                if(!is_continue)
                    break;
            }
            
            count[c - 'a'] = 0;
        }
        cout << i << endl;
        return strs[0].substr(0, i-1);
    }
};