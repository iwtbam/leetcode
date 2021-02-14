#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:

    inline string getKey(const string& str){
        string nkey(26, '0');
        int size = str.size();
        for(int i = 0; i < size; i++)
            nkey[str[i]-'a']++;
        return move(nkey);
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();        
        vector<int> visited = {size, 0};
        unordered_map<string, vector<string>> record = {};

        for(int i = 0; i < size; i++)
        {
            record[getKey(strs[i])].push_back(strs[i]);
        }
        
        vector<vector<string>> res = {};
        for(auto& p: record)
            res.push_back(p.second);
        
        return res;
        
    }
};