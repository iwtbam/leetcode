// https://leetcode-cn.com/problems/stone-game-iii/
// stone game iii
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int size = stoneValue.size();
        vector<int> dp(size + 3, INT_MIN);
        dp[size] = 0;
        dp[size + 1] = 0;
        dp[size + 2] = 0;
        //int sum = stoneValue[size - 1];

        int sum = 0;
     
        for(int i = size - 1; i >= 0; i--){
           sum += stoneValue[i];
           for(int j = 1; j <= 3; j++){
               dp[i] = max(dp[i], sum - dp[i + j]);
           }
        }

    
        if(dp[0] * 2 == sum)
            return "Tie";
        if(dp[0] * 2 >= sum)
            return "Alice";
        return "Bob";
    }
};