// https://leetcode-cn.com/problems/tallest-billboard/
// tallest billboard
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int total = accumulate(rods.begin(), rods.end(), 0);
        sort(rods.begin(), rods.end(), greater<int>());
        //cout << total << endl;
        int res = 0;

        solve(rods, 0, 0, 0, res, total);

        return res;
    }

    void solve(vector<int>& rods, int step, int left, int right, int& res, int remain) {

        if(abs(left - right) > remain || (left + right + remain + 1) >> 1 <= res)
            return;
        
        if(left == right){
            res = max(res, left);
        }

        if(step >= rods.size())
            return;

        
        solve(rods, step + 1, left + rods[step], right, res, remain - rods[step]);
        solve(rods, step + 1, left, right + rods[step], res, remain - rods[step]);
        solve(rods, step + 1, left, right, res, remain - rods[step]);
        return;
    }
};