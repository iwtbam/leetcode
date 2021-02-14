// https://leetcode-cn.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
// the k th lexicographical string of all happy strings of length n
class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> res = {};
        string cur = {};
        solve(n, k, cur, res);
        return res.size() >= k ? res[k - 1] : "";
    }
    
    void solve(int n, int k,  string& cur, vector<string>& res){
        static vector<char> chs = {'a', 'b', 'c'};
        
        if(cur.size() == n){
            res.push_back(cur);
            return;
        }
        
     
        
        for(int i = 0; i < 3; i++){
            if(cur.size() > 0 && chs[i] == cur.back())
                continue;
            if(res.size() >= k)
                return;
            cur.push_back(chs[i]);
            solve(n, k, cur, res);
            cur.pop_back();
        }
        
        return;
    }
};