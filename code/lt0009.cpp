#include <sstream>
#include <string>

using namespace std;

template<typename T>
string convert(T val)
{
    stringstream ss;
    ss << val;
    return ss.str();
}

class Solution {
public:
    bool isPalindrome(int x) {
        string s = convert(x);
        for(int i = 0, j = s.size(); i < j ; i++, j--)
            if(s[i] != s[j])
                return false;
        return true;
    }
};