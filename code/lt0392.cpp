#include <vector>
#include <string>

using namespace std;


#define S2

#if defined S1
// 2019-07-23 超时严重 做复杂了

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s == t)
            return true;
        
        if(s.empty())
            return true;
        
        if(t.empty())
            return false;
        
        if(s.size() >  t.size())
            return false;
        
        vector<int> dp(t.size(), 0);
        dp[0] = (s[0] == t[0]);

        int s1 = s.size(), s2 = t.size();

        for(int i = 1; i < s2; i++)
            dp[i] = dp[i-1] || (s[0] == t[i]);

        for(int i = 1; i < s1; i++)
        {
            
            for(int j = s2 - 1; j >= i; j--)
            {
                dp[j] = dp[j-1] && (s[i] == t[j]);
            }

            for(int j = i + 1; j < s2; j++)
                dp[j] = dp[j-1] == 1 ? 1 : dp[j];
        }

        return dp[s2 - 1];
    }
};

#else

class Solution {
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (auto c : s) {
            while (i != t.length() && c != t[i]) ++i;
            if (i == t.length()) return false;
            ++i;
        }
        return true;
    }
};

#endif