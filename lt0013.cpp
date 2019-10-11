#include <string>
#include <unordered_map>

using namespace std;

class Solution {

public:
    int romanToInt(string s){
        int sign = 1;
        int res = 0;
        int size = s.size();
        for(int i = 0; i < size - 1; i++){
            sign = record[s[i+1]] <= record[s[i]] ? 1 : -1;
            res += sign * record[s[i]];
        }

        res += record[s[size-1]];
        return res;
    }

private:
    unordered_map<char, int> record = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
};

