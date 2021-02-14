// https://leetcode-cn.com/problems/group-anagrams-lcci/
// group anagrams lcci
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> hash = strs;
        
        unordered_map<string, vector<string>> res;
        size_t size = hash.size();

        for(int i = 0; i < size; i++)
            sort(hash[i].begin(), hash[i].end());

        for(int i = 0; i < size; i++){
            res[hash[i]].push_back(strs[i]);
        }

        vector<vector<string>> v;

        for(auto& [k, val] : res)
            v.push_back(val);

        return v;
    }
};