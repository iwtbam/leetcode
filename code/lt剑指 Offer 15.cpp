// https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
// er jin zhi zhong 1de ge shu lcof
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while(n){
            n = n & (n - 1);
            num++;
        }

        return num;

    }
};