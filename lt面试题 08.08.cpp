// https://leetcode-cn.com/problems/permutation-ii-lcci/
// permutation ii lcci
class Solution {
public:
    vector<string> permutation(string S) {
        size_t n = S.size();
        vector<int> vis(n, 0);
        vector<string> res;
        string item;
        sort(S.begin(), S.end());
        dfs(res, S, item, vis);
        return res;
    }

    void dfs(vector<string>& res, string& S, string& item, vector<int>& vis){
        
        if(S.size() == item.size()){
            res.push_back(item);
            return;
        }
        
        unordered_set<char> record;
        size_t size = S.size();
        
        for(int i = 0; i < size; i++){
            if(record.count(S[i]) == 1 || vis[i] == 1)
                continue;
            
            record.insert(S[i]);

            vis[i] = 1;
            item.push_back(S[i]);
            dfs(res, S, item, vis);
            item.pop_back();
            vis[i] = 0;
        }
    }
};