#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        if(a.size() < b.size())
            a.swap(b);
        a = string{"0"} + a;
        
        int co = 0, bsize = b.size(), asize = a.size();
        int i = 0;
        for(; i < bsize; i++)
        {
            int num = a[asize - i - 1] - '0' + b[bsize - i - 1] - '0' + co;
            a[asize - i - 1] = num % 2 + '0';
            co = num / 2 ;
        }
        while(co)
        {
            int num = a[asize - i - 1]  - '0' + co;
            a[asize - i - 1] = num % 2 + '0';
            co = num / 2;
            i++;
        }

        if(a[0] == '0')
            return a.substr(1);
        return a;
    }
};