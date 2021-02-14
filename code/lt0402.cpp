#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k >= num.size())
            return {"0"};
        
        vector<char> cv;
        int nsize = num.size();
    
        int i = 0;

        for(; i < nsize && k; i++)
        {
            if(cv.size())
            {
                char top = cv.back();
                while(cv.size() && num[i] < top)
                {
                    cv.pop_back();
                    k--;
                    
                    if(k == 0)
                        break;
                    if(cv.size())
                        top = cv.back();
                }
            }
            
            cv.push_back(num[i]);
        }

        for(;i<nsize;i++)
            cv.push_back(num[i]);
        
        while(k){
            cv.pop_back();
            k--;
        }
        
        int offset = 0;
        while(offset < cv.size() && cv[offset]=='0')
            offset++;
        
        if(offset < cv.size())
            return {cv.begin() + offset, cv.end()};
        return {"0"};
    }
};