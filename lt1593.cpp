// https://leetcode-cn.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
// split a string into the max number of unique substrings
class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> record;
        return check(s, record, "", 0, 0);
    }
    
    int check(const string& s, unordered_set<string>& record, string word,  int split, int cur)
    {
        if(cur == s.size())
        {
            if(word.size() == 0)
                return split;
            
            if(record.count(word) == 0)
                return split + 1;
            
            return 1;
        }
        
        int ans = 1;
        
        word.push_back(s[cur]);
        ans = max(ans, check(s, record, word, split, cur + 1));
        
        if(record.count(word) == 0)
        {
            record.insert(word);
            ans = max(ans, check(s, record, "", split + 1, cur + 1));
            record.erase(word);
        }
        
       
        
        return ans;
    }
};