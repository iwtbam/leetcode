#include <string>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if(n == 0)
            return 0;

        if(n <= 3)
            return 1;

        string s = {"122"};
        int t = 2, p = s.size();
        int res = 0;
        while(p <= n){
            char c = s[p - 1] == '1' ? '2' : '1';
            int times = s[t++] - '0';
            for(int i = 0; i < times; i++)
                s.push_back(c);
            p = s.size();

        }

        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                res++;
        }

        return res;
    }
};