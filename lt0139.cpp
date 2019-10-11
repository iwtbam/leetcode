#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        
        int ssize = s.size();
        
        if(ssize == 0)
            return true;
        
        int wsize = wordDict.size();
        
        vector<int> dp(ssize, 0);
        
        for(auto& word:wordDict)
        {
            if(word.size() <= ssize && s.substr(0, word.size()) == word)
                dp[word.size() - 1] = 1;
        }
        
        for(int i = 0; i < ssize; i++)
        {
            if(dp[i] == 0)
                continue;
            
            for(auto& word:wordDict)
            {
                if(i + word.size() < ssize && s.substr(i+1, word.size()) == word)
                    dp[i+word.size()] = 1;
            }
        }

        
        return dp[ssize  - 1];
    }
};