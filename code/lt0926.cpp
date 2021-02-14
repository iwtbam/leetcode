// https://leetcode-cn.com/problems/flip-string-to-monotone-increasing/
// flip string to monotone increasing
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int size = S.size();
        vector<int> left(size, 0);
        vector<int> right(size, 0);
        left[0] = S[0] - '0';

        int sum = 0;

        for(int i = 1; i < size; i++){
            left[i] = left[i - 1] + S[i] - '0';
        }

        sum = left[size - 1];
        int op = size - sum;
        for(int i = 0; i < size; i++){
            int ones = left[i];
            int zeros = size - i - 1 - (sum - left[i]);
            op = min(op, ones + zeros);
        }

        return op;
    }
};