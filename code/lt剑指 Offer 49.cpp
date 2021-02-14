// https://leetcode-cn.com/problems/chou-shu-lcof/
// chou shu lcof
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res = {}; 
        res.push_back(1);
        int p2 = 0, p3 = 0, p5 = 0;\
        for(int i = 2; i <= n; i++){
            int min_ele = min(res[p2] * 2, min(res[p3] * 3, res[p5] * 5));
            if(min_ele == res[p2] * 2)
                p2++;
            if(min_ele == res[p3] * 3)
                p3++;
            if(min_ele == res[p5] * 5)
                p5++;
            res.push_back(min_ele);
        }
        return res.back();
    }
};