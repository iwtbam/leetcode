#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> record;
        helper(res, record, s, 0);
        return res;
    }
    
    void helper(vector<string>& res, vector<int>& record, string s, int step)
    {
        if(record.size() == 3)
        {
            int last_pos = record.back();
            if(last_pos == s.size())
                return;
            if(s.size() - last_pos > 3)
                return;
            if(s.size() - last_pos == 3 && s.substr(last_pos) > string("255"))
                return;
            if(s.size() - last_pos > 1 && s[last_pos] == '0')
                return;
           
            for(int i = 2; i >=0;i--)
                s.insert(record[i], ".");
            res.push_back(s);
        }
        
        for(int i = step + 1; i <= step + 3 &&i <= s.size(); i++)
        {
            
            if(i - step == 3 && s.substr(step, i - step) > string("255"))
                continue;
            
            record.push_back(i);
            helper(res, record, s, i);
            record.pop_back();

            if(i==step+1&&s[step]=='0')
                break;
        }
        
    }
};