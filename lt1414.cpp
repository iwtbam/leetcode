// https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
// find the minimum number of fibonacci numbers whose sum is k
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> arrs = build(k);
        size_t size = arrs.size();
        int cnt = 0;
        for(int i = size - 1; i >= 0; i--){
            if(k >= arrs[i]){
                k = k - arrs[i];
                cnt++;
            }

            if(k == 0)
                break;
        }

        return cnt;
    }

    vector<int> build(int k){
        vector<int> arrs = {1, 1};
        int step = 2;
        while(arrs.back() < k){
            arrs.push_back(arrs[step - 1] + arrs[step - 2]);
            step++;
        }
        return arrs;
    }
};