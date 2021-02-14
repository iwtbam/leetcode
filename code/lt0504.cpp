#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        
        if(num == 0)
            return {"0"};
        
        vector<int> record;
        int flag = num >= 0 ? 1:0;
        num = abs(num);
        while(num)
        {
            record.push_back(num % 7);
            num = num / 7;
        }
        
        string res = {};
        for(auto& i : record)
            res += to_string(i);
        if(!flag)
            res =  res + string{"-"};
        
        return {res.rbegin(), res.rend()};
    }
};