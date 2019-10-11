#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> record1;
        unordered_map<char, char> record2;
        if(s.size() != t.size())
            return false;
        
        int size = s.size();
        
        for(int i = 0; i < size; i++)
        {
            if(record1.find(s[i])==record1.end())
            {
                if(record2.find(t[i]) != record2.end())
                    return false;
                record1[s[i]] = t[i];
                record2[t[i]] = s[i];
            }
            
            if(record1[s[i]]!=t[i])
                return false;
        }
        
        return true;
    }
};