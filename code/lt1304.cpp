// https://leetcode-cn.com/problems/find-n-unique-integers-sum-up-to-zero/
// find n unique integers sum up to zero
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res = {};
        int half = n / 2;
        for(int i = half; i >= 1; i--)
            res.push_back(i * -1);
        if(n % 2 == 1)
            res.push_back(0);
        for(int i = 1; i <= half ; i++)
            res.push_back(i);
        return res;
    }
};