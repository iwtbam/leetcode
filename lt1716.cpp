// https://leetcode-cn.com/problems/calculate-money-in-leetcode-bank/
// calculate money in leetcode bank
class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        
        
        for(int i = 1; i <= n; i++){
            int seg = i / 7 + (i % 7 != 0);
            int num = seg + (i - 1) % 7;
            // cout << num << ",";
            ans += num;
        }
        // cout << endl;
        
        return ans;
    }
};