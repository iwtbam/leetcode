// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
// zi fu chuan de pai lie lcof
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        size_t  size = s.size();
        vector<int> vis(size, 0);
        string path;
        helper(s, path, res, vis, 0);
        return res;
    }

    void helper(const string& s, string& path, vector<string>& res, vector<int>& vis, int step){
        if(step == s.size()){
            res.push_back(path);
            return;
        }
        size_t size = s.size();
        set<char> norepeat;
        for(int i = 0; i < size; i++){
            if(vis[i])
                continue;
            if(norepeat.count(s[i]))  
                continue;
            norepeat.insert(s[i]);
            vis[i] = 1;
            path.push_back(s[i]);
            helper(s, path, res, vis, step + 1);
            path.pop_back();
            vis[i] = 0;
        }
    }
};