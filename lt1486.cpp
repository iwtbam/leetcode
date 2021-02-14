// https://leetcode-cn.com/problems/xor-operation-in-an-array/
// xor operation in an array
class Solution {
public:
    int xorOperation(int n, int start) {
        long long res = 0;
        for(int i = 0; i < n; i++){
            res = res ^ (start + 2 * i);
        }
        return res;
    }
};