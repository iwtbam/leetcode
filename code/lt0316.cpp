#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        if(s.empty())
            return {};
        vector<char> iv;
        size_t count[26] = {0}, ncount[26] = {0};
        int size = s.size();
        for(int i = 0; i < s.size(); i++)
            count[s[i]-'a']++;
        iv.push_back(s[0]);
        ncount[s[0] - 'a'] = 1;

        for(int i = 1; i < size; i++)
        {
            if(iv.size() && ncount[s[i]-'a'] < 1)
            {
                char top = iv.back();
                while(iv.size() && top >= s[i] && count[top - 'a'] > 1)
                {
                    count[top - 'a']--;
                    ncount[top - 'a']--;
                    iv.pop_back();
                    if(iv.size())
                        top = iv.back();
                }

                ncount[s[i] - 'a']++;
                iv.push_back(s[i]);
            }
            else
            {
                if(iv.size())
                    count[s[i]-'a']--;
            }
        }
        

        return {iv.begin(), iv.end()};
    }
};