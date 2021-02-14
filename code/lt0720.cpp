// https://leetcode-cn.com/problems/longest-word-in-dictionary/
// longest word in dictionary
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), 
            [](const string& s1, const string& s2){ 
                if(s1.size() == s2.size())
                    return s1 < s2;
                return s1.size() < s2.size();
            });
        

        unordered_set<string> record = {};
        string res = "";
        record.insert("");

        for(int i = 0; i < words.size() ; i++){
            int size = words[i].size();
            string prefix = words[i].substr(0, size - 1);
            if(record.count(prefix)==1){
                if(words[i].size() > res.size())
                    res = words[i]; 
                record.insert(words[i]);
            }
        }

        return res;
    }
};