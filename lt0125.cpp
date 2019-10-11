#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    
    inline bool isIgnore(char c)
    {
        if(c >='a' && c <= 'z')
            return false;
        if(c >='A' && c <= 'Z')
            return false;
        if(c >='0' && c <= '9')
            return false;
        return true;
    }
    
    inline bool isChar(char c)
    {
        if(c>='a' && c<='z')
            return true;
        
        if(c>='A' && c<='Z')
            return true;
        return false;
    }
    
    inline bool isEqual(char c1,char c2)
    {
        if(c1 == c2)
            return true;
        
        if(isChar(c1) && isChar(c2) && abs(c1 - c2) == 32)
            return true;
        return false;
    }
    
    bool isPalindrome(string s) {
        
        if(s.size() < 2)
            return true;
        
        int l = 0;
        int r = s.size() -1;
        while(l < r)
        {
            while(l < r && isIgnore(s[l]))
                l++;
            while(l < r && isIgnore(s[r]))
                r--;
            
            if(l >= r)
                break;
                
            if(!isEqual(s[l], s[r]))
                return false;  
            l++, r--;
        }
        
        return true;
    }
};