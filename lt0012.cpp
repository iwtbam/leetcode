#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<string> values = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };

    vector<int> index = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
    };

    string intToRoman(int num) {
        
        int len = index.size();
        stringstream ss;
        string s;
        for(int i = 0; i < len ;i++)
        {
            int high = num / index[i];
            num =  num - high * index[i];
            for(int j = 0 ; j< high; j++)
                s += values[i];
        }
        return s;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    string res = s.intToRoman(1994);
    cout << res << endl;
    return 0;
}