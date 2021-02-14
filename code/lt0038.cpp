#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = {"1"};
        if(n == 1)
            return s;
        int cur = 1;
        while(cur < n)
        {
            
            size_t count = 1;
            string next = {};
            int i = 0;
            int size = s.size() - 1;
            for(; i < size; i++)
            {
                if(s[i] == s[i+1])
                    count++;
                else
                {
                    next = next + to_string(count) + s[i];
                    count = 1;
                }
            }
            next = next + to_string(count) + s[i];
            s = next;
            cur++;
        }
        
        return s;
    }
};