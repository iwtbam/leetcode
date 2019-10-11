#include <iostream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int flag = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '0')
                flag = 0;
            
            if(s[i] != '0' && !flag) 
            {
                flag = 1;
                count++;
            }
        }
        
        return count;
    }
};