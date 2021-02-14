// https://leetcode-cn.com/problems/determine-if-two-strings-are-close/
// determine if two strings are close
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size())
            return false;
        
        vector<int> record(26, 0);
        size_t size = word1.size();
        
        for(int i = 0; i < size; i++)
            record[word1[i] - 'a'] = 1;
        
        for(int i = 0; i < size; i++)
            if(record[word2[i] - 'a'] == 0)
                return false;
        
        
        vector<int> p1 = pre(word1);
        vector<int> p2 = pre(word2);
        
        if(p1.size() !=  p2.size())
            return false;
        size = p1.size();
        for(int i = 0; i< size; i++)
            if(p1[i] != p2[i])
                    return false;
        return true;
    }
    
    vector<int> pre(const std::string& s)
    {
        vector<int> record(26, 0);
        size_t size = s.size();
        for(int i = 0; i < size; i++)
            record[s[i] - 'a']++;
        vector<int> res;
        for(int i = 0; i < 26; i++)
        {
            if(record[i] != 0)
                res.push_back(record[i]);
        }
        sort(res.begin(), res.end());
        return res;
    }
};