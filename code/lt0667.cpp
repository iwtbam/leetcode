// https://leetcode-cn.com/problems/beautiful-arrangement-ii/
// beautiful arrangement ii
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res = {};
        res.push_back(1);

        int sign = 1;

        for(int i = k; i >= 1; i--){
            res.push_back(res.back() + sign * i);
            sign = -sign;
        }

        for(int i = k + 2; i <= n; i++)
            res.push_back(i);

        return res;
    }
};