// https://leetcode-cn.com/problems/permutation-i-lcci/
// permutation i lcci
class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> res;
        string item;
        vector<int> vis(S.size(), 0);
        dfs(res, item, S, vis);
        return res;
    }

    void dfs(vector<string>& res, string& item, string& S, vector<int>& vis){
        if(item.size() == S.size()){
            res.push_back(item);
            return;
        }

        size_t size = S.size();

        for(int i = 0; i < size; i++){
            if(vis[i] == 1)
                continue;

            vis[i] = 1;
            item.push_back(S[i]);
            dfs(res, item, S, vis);
            item.pop_back();
            vis[i] = 0;
        }

        return;
    }

};