// https://leetcode-cn.com/problems/get-maximum-in-generated-array/
// get maximum in generated array
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n < 2)
            return n;
        int ans = 1;
        vector<int> data(n + 1, 0);
        data[0] = 0;
        data[1] = 1;
        for(int i = 2; i <= n; i++){
            if(i % 2 == 0)
                data[i] = data[i / 2];
            else
                data[i] = data[i / 2] + data[i / 2 + 1];
            ans = max(ans, data[i]);
        }
        return ans;
    }
};