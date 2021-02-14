// https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// minimum insertion steps to make a string palindrome
class Solution {
public:
    int minInsertions(string s) {
        string p = {s.rbegin(), s.rend()};
        size_t size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                int left  = i - 1 >= 0 ? dp[i - 1][j] : 0;
                int right = j - 1 >= 0 ? dp[i][j - 1] : 0;
                int pre = i - 1 >= 0 && j - 1 >= 0 ? dp[i - 1][j - 1] : 0;
                if(s[i] == p[j])
                    dp[i][j] =pre + 1;
                else
                    dp[i][j] = max(left, right);
            }
        }
        
        int common_size = dp[size - 1][size - 1];
        
        return size - common_size;
    }
};