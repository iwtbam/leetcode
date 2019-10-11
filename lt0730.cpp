#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> record1;
        unordered_map<string,char>  record2;
        int j = 0, l = 0, count = 0;
        for(int i = 0; i < pattern.size();i++)
        {
            l = 0;
            while(j + l < str.size() && str[j + l]!=' ')
                l++;
            
            if(j + l > str.size())
                return false;
            
            string word = str.substr(j, l);
            count++;
            if(record1.find(pattern[i])==record1.end())
            {
                if(record2.find(word)!=record2.end())
                    return false;
                
                record1[pattern[i]] = word;
                record2[word] = pattern[i];
            }
            
            if(record1[pattern[i]]!=word)
                return false;
            j = j + l + 1;
        }
       
        if(j < str.size())
            return false;
        
        return true;
    }
};