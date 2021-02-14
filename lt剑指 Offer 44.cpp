// https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/
// shu zi xu lie zhong mou yi wei de shu zi lcof
class Solution {
public:
    int findNthDigit(int n) {
        int base = 10;
        
        if(n < base){
            return n;
        }

        n -= base;
        int e = 1;
        
        while(n > 9 * pow(10, e) * (e + 1)){
            n -= 9 * pow(10, e) *  (e + 1);
            e += 1;
        }

        string num = to_string(static_cast<int>(pow(10, e)) + n / (e + 1));
        return num[n % (e + 1)] - '0';
    }
};