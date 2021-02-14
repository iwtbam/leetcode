#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp;
        string res = {};
        while(ss >> temp){
            if(res.empty())
                res = temp;
            else
                res = temp + " " + res;
        }
        
        return res;
    }
};