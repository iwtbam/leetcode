// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

#define DEBUG

#if defined(S1)

// 我感觉会超时, 没有提交, 时间复杂度太高
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> vec(s.size(), 0);
        vector<vector<int>> vec2(s.size(), vec);

        for(int i = 0; i < s.size(); i++)
            vec2[i][i] = 1;

        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] == '(' && s[i+1] == ')')
                vec2[i][i+1]  =2;
        }


        int len = 0;
        for(int l = 3; l <= s.size(); l++)
        {
            for(int i = 0; i < s.size() - l + 1; i++)
            {
                int j = i + l - 1;


                if(l % 2)
                {
                    vec2[i][j] = max(vec2[i+1][j], vec2[i][j-1]); 
                }
                else
                {
                    for(int k = i + 1; k < j; k += 1)
                    {
                        if(vec2[i][k]==(k-i+1) && vec2[k+1][j] == (j-k))
                            vec2[i][j] = l;
                        else
                            vec2[i][j] = max(vec2[i][j], max(vec2[i][k], vec2[k+1][j]));
                    }

                    if(s[i] == '(' && s[j] == ')')
                    {
                        if(vec2[i+1][j-1]==(j-i-1))
                            vec2[i][j] = l;
                    }
                }  
            }
        }

        #ifdef DEBUG

        for(int i = 0; i<s.size();i++)
        {
            for(int j = 0; j < s.size(); j++)
            {
                cout << vec2[i][j] << ends; 
            }

            cout << endl;
        }

        #endif

        return vec2[0][s.size()-1];
    }
};

#elif defined(S2)
//  超出内存了
class Solution {
public:
    int longestValidParentheses(string s) {
       stack<pair<int, char>> is;
       vector<int> vec(s.size(), 0);
       vector<vector<int>> vec2(s.size(), vec);

       int cl(-1), cr(-1), ml(0), mr(0);
       
       for(int i = 0; i < s.size(); i++)
       {
           if(is.empty())
           {
                is.emplace(i, s[i]);
                continue;
           }

           if(s[i] > is.top().second)
           {
                cr = i;
                cl = is.top().first;
                
                for(int i = cl - 2; i >=0; i-=2)
                {
                    if(vec2[i][cl - 1])
                        cl = i;
                }
                
                if(cr - cl > mr - ml)
                {
                    ml = cl;
                    mr = cr;
                }

                vec2[cl][cr]  = 1;
                is.pop();
           }
           else
               is.emplace(i, s[i]);
       }

       if(ml == mr)
            return 0;

       return mr - ml + 1;
    }
};

#else

class Solution {
public:
    int longestValidParentheses(string s) {
       stack<pair<int, char>> is;
       vector<int> vec(s.size(), 0);

       int cl(-1), cr(-1), ml(0), mr(0);
       
       for(int i = 0; i < s.size(); i++)
       {
           if(is.empty())
           {
                is.emplace(i, s[i]);
                continue;
           }

           if(s[i] > is.top().second)
           {
                cr = i;
                cl = is.top().first;
                
                for(int i = cl - 2; i >=0; i-=2)
                {
                   if(vec[i] == cl - 1)
                        cl = i;
                }
                
                if(cr - cl > mr - ml)
                {
                    ml = cl;
                    mr = cr;
                }

                vec[cl]  = cr;
                is.pop();
           }
           else
               is.emplace(i, s[i]);
       }

#ifdef DEBUG

    for(int i = 0 ; i < vec.size() ;i++)
        cout << vec[i] << ends;
    cout << endl;
#endif

       if(ml == mr)
            return 0;

       return mr - ml + 1;
    }
};


#endif

int main()
{
    Solution s;
    int r = s.longestValidParentheses("(()");
    cout << r << endl;
    r = s.longestValidParentheses(")()())");
    cout << r << endl;           //01234567890123456789012345678901234567890123456789
    r = s.longestValidParentheses("()())))((()()()((((()(()(()()()(((()))))(()()()(");
    cout << r << endl;
    r = s.longestValidParentheses("");
    cout << r << endl;
    return 0;
}

// 我感觉我的dp有了一点长进