#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        size_t l1 = text1.size();
        size_t l2 = text2.size();
        vector<vector<int>> dp = {l1, vector<int>(l2, 0)};
        for(int i = 0; i < l1; i++){
            for(int j = 0; j < l2; j++){
                int left  = i >= 1 ? dp[i - 1][j] : 0;
                int right = j >= 1 ? dp[i][j - 1] : 0;
                int pre   = i >= 1 && j >= 1 ? dp[i - 1][j - 1] : 0;
                if(text1[i] == text2[j]){
                    dp[i][j] = pre + 1;
                }else{
                    dp[i][j] = max(left, right);
                }
            }
        }
        return dp[l1 - 1][l2 - 1];   
    }
};

