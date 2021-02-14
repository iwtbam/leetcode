#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> record(26, 0);
        for(int i = 0; i < s.size(); i++)
            record[s[i] - 'a']++;
        
        for(int i = 0; i < t.size(); i++){
            if(record[t[i] - 'a'] == 0)
                return t[i];
            record[t[i] - 'a']--;
        }
        return 'a';
    }
};