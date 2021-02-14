#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        vector<int> vec(s.size() + 1, 0);
        vector<vector<int>> vec2(p.size() + 1, vec);

        vec2[0][0] = 1;

        for(int i = 1; i <= p.size(); i++)
        {
            vec2[i][0] = p[i-1] != '*' ? 0:
                            (i > 1 ? vec2[i-2][0] : 0) || vec2[i-1][0] ; 

            for(int j = 1; j <= s.size(); j++)
            {
                if(p[i-1]=='*')
                {
                    if(i > 1)
                        vec2[i][j] = vec2[i-2][j];
                        
                    vec2[i][j] = vec2[i][j] || vec2[i-1][j] || 
                                 ((vec2[i-1][j-1] || vec2[i][j-1]) && 
                                 (i > 1 &&(p[i-2]=='.' || p[i-2]==s[j-1])));                    
                    
                }
                else
                    vec2[i][j] = vec2[i-1][j-1] && ( p[i-1] == '.' || s[j-1] == p[i-1]);
            }

#ifdef DEBUG

        for(int j = 0; j <= s.size(); j++)
        {
            for(int i = 0; i <= p.size(); i++)
                cout << vec2[i][j] << ends;
            cout << endl;
        }

#endif
        return vec2[p.size()][s.size()];
    }
};

int main()
{
    Solution s;
    bool r = s.isMatch("aa", "a");
    cout << r << ends;
    r = s.isMatch("aa", "a*");
    cout << r << ends;
    r = s.isMatch("ab", ".*");
    cout << r << ends;
    r = s.isMatch("aab", "c*a*b");
    cout << r << ends;
    r = s.isMatch("mississippi", "mis*is*p*");
    cout << r << ends;
    r = s.isMatch("ab", "*ab");
    cout << r << endl;
    return 0;
}