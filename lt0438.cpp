// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
// find all anagrams in a string
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ss = s.size();
        int ps = p.size();

        if(ps > ss)
            return {};

        vector<int> res = {};
        
        int hash1[26] = {0};
        int hash2[26] = {0};

        hash(p, hash1);
        string prefix = s.substr(0, ps);
        hash(prefix, hash2);
        
        if(check(hash1, hash2))
            res.push_back(0);

        for(int i = ps; i < ss; i++){
            hash2[s[i] - 'a']++;
            hash2[s[i - ps] - 'a']--;
            if(check(hash1, hash2))
                res.push_back(i - ps + 1);
        }

        return res;
    }

    int check(int* hash1, int* hash2){
        for(int i = 0; i < 26; i++){
            if(hash1[i]!=hash2[i])
                return 0;
        }
        return 1;
    }

    void hash(const string& p, int* hashcode){
        for(int i = 0; i < p.size(); i++)
            hashcode[p[i] - 'a']++;
        return;
    }
};