// https://leetcode-cn.com/problems/palindrome-partitioning-ii/
// palindrome partitioning ii
class Solution {
public:
    int minCut(string s) {

        int size = s.size();
        if(size == 0)
            return 0;

        vector<vector<int>> dp = {size, vector<int>(size, 0)};

        for(int len = 2; len <= size; len++){
            for(int i = 0; i < size - len + 1; i++){
                int j = i + len - 1;
                
                if(check(s, i, j + 1))
                    continue;
                dp[i][j] = INT_MAX;
                for(int s = i; s < j; s++){
                    dp[i][j] = min(dp[i][j], dp[i][s] + dp[s + 1][j]);
                }

                dp[i][j]++;
            }
        }

        return dp[0][size - 1];
    }

    int minCut(string& s, int left, int right){
        
        if(check(s, left, right))
            return 0;

        int min_num = INT_MAX;
        for(int i = left + 1; i < right; i++){
            
            int left_cut_num = check(s, left, i);
            int right_cut_num = check(s, i, right);
            int num = 1;
            
            if(left_cut_num == 0)
                num += minCut(s, left, i);
            
            if(right_cut_num == 0)
                num += minCut(s, i, right);
            min_num = min(min_num, num);
        }

        return min_num;
    }

    int check(string& s, int left,  int right){
        int p1 = left, p2 = right - 1;
        while(p1 < right && p2 >= 0 && p1 < p2){
            if(s[p1] != s[p2])
                return 0;
            p1++;
            p2--;
        }
        return 1;
    }
};