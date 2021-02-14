// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        vector<int> vec(s.size(), 0);
        vector<vector<int>> vec2(s.size(), vec);
        for(int i = 0; i < s.size();i++)
            vec2[i][i] = 1;
        
        int maxLen = 1;
        int left = 0, right = 0;

        for(int l = 2; l <= s.size(); l++)
        {
            for(int i = 0; i < s.size() - l + 1; i++)
            {
                int j = i + l - 1;

                if(s[i]==s[j])
                {
                    if(i+1>j-1)
                        vec2[i][j] = 2;
                    else if(vec2[i+1][j-1])
                        vec2[i][j] = vec2[i+1][j-1] + 2;
                    else
                        vec2[i][j] = 0;
                    
                    if(vec2[i][j] > maxLen)
                    {
                        maxLen = vec2[i][j];
                        left = i;
                        right = j;
                    }
                }
            }
        }

        return s.substr(left, right - left + 1);
    }
};

int main()
{
    Solution s;
    string s1 = s.longestPalindrome("abcda");
    cout << s1 << endl;
    return 0;
}