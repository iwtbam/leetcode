#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define S2

#if defined (S1)
class Solution{
public:
    string convert(string s, int numRows){
    
        int len = numRows % 2 ? (numRows + 1) * (numRows + 1) : (numRows + 2) * numRows;
        len = len / 4;

        int size = s.size();
        string dst;

        for(int i = 0 ; i < numRows; i++)
        {
            for(int j = i; j < size ; j += len)
            {
                if(j < size)
                    dst.push_back(s[j]);
                if(i!=0 && i!=numRows-1)
                {
                    if(j + len - 2 * i < size)
                        dst.push_back(s[j + len - 2 * i]);
                }
            }
        }
        return dst;
    }
};
#elif defined(S2)

class Solution{
public:
    string convert(string s, int numRows){
        
        vector<string> lines(min(static_cast<int>(s.size()), numRows));
        int len = 2 * numRows - 1;
        int size = s.size();
        for(int i = 0; i < size; i++)
        {
            if(i % len <= numRows)
                lines[i % len].push_back(s[i]);
            else
                lines[len - i % len -1].push_back(s[i]);
            
        }

        return accumulate(lines.begin(), lines.end(), "");
    }
        
};

#endif
