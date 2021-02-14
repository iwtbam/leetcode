// https://leetcode-cn.com/problems/palindrome-partitioning/
// palindrome partitioning
class Solution {
public:
    vector<vector<string>> partition(string s) {
        size_t size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 1));
        vector<vector<string>> res;
        vector<string> item;
        for(int len = 2; len <= size; len++){
            for(int i = 0; i < size - len + 1; i++){
                int j = i + len - 1;
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        split(dp, s, item, res, 0);
        return res;
    }


    void split(vector<vector<int>>& dp, const string& s, vector<string>& item, vector<vector<string>>& res, int cur){
        size_t size = s.size();
        if(cur == size){
            res.push_back(item);
            return;
        }

        for(int i = cur; i < size; i++){
            if(dp[cur][i] && ( i >= cur || dp[i + 1][size - 1])){
                item.push_back(s.substr(cur, i - cur + 1));
                split(dp, s, item, res, i + 1);
                item.pop_back();
            }
        }
        return;
    }
};