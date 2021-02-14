// https://leetcode-cn.com/problems/maximum-number-of-occurrences-of-a-substring/
// maximum number of occurrences of a substring
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> count = {};
        int size = s.size();
        for(int i = 0; i < size - minSize + 1; i++){
            string key = s.substr(i, minSize);
            count[key]++;
        }

        int res = 0;
        for(const pair<string, int>& p : count){
            if(check(p.first, maxLetters) && p.second > res)
                res = p.second;
            
        }

        return res;
    }

    bool check(string key, int maxLetters){
        int hash[26] = {0};
        int size = key.size();
        for(int i = 0; i < size; i++)
            hash[key[i] - 'a']++;
        int letters = 0;
        for(int i = 0; i < 26; i++){
            letters += (hash[i] == 0 ? 0 : 1);
        }

        return letters <= maxLetters;
    }
};