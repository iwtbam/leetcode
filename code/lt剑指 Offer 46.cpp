// https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
// ba shu zi fan yi cheng zi fu chuan lcof
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        const string th("26");
        int size = s.size();
        if(size == 1)
            return 1;
        vector<int> dp(size, 0);
        dp[0] = 1;
        dp[1] = 1;
        if(s[0] != '0' && s.substr(0, 2) < th)
            dp[1] += 1;
       
        for(int i = 2; i < size; i++){
            dp[i] = dp[i - 1];
            if(s[i - 1] != '0' && s.substr(i - 1, 2) < th)
                dp[i] += dp[i - 2];   
         }

        return dp[size - 1];

    }
};