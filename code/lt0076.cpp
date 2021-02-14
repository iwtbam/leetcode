#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need = {};
        unordered_map<char, int> window = {};
        
        for(char c:t)
            need[c]++;
        
        int left = 0, right = 0;
        int min_len = INT_MAX, min_left = 0;
        int match = 0;

        while(right < s.size())
        {
            char rc = s[right];
            if(need.count(rc))
            {
                window[rc]++;
                if(window[rc] == need[rc])
                    match++;
            }
          
            while(match == need.size())
            {
               
                if(right - left + 1 < min_len)
                {
                    min_len = right - left + 1;
                    min_left = left;
                }
                
                char lc = s[left];
                if(need.count(lc))
                {
                    window[lc]--;
                    if(window[lc] < need[lc])
                        match--;
                }

                left++;
            }

            right++;
        }

        if(min_len == INT_MAX)
            return "";
        return s.substr(min_left, min_len);
    }
};