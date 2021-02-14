// https://leetcode-cn.com/problems/reverse-integer/
// reverse integer
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

template<typename _InputType, typename _OutputType>
_OutputType convert(_InputType val)
{
    stringstream ss;
    _OutputType output;
    ss << val;
    ss >> output;
    return output;
}

string rever(string src)
{
    return string(src.rbegin(), src.rend());
}

class Solution {
public:
    string reverse(string src)
    {
        return string(src.rbegin(), src.rend());
    }

    int reverse(int x) {
        int sign = x >= 0 ? 1 : -1;
        long long num = convert<string ,long long>(reverse(convert<int,string>(x)));
        num = num > INT_MAX ? 0 : num;
        return sign * num;
    }
};