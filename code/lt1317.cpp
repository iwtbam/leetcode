// https://leetcode-cn.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
// convert integer to the sum of two no zero integers
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int half = n / 2;
        for(int i = 1; i <= half; i++){
            if(check(i) && check(n - i))
                return {i, n - i};
        }
        
        return {1, n - 1};
    }
    
    bool check(int num){
        while(num){
            int bit = num % 10;
            if(bit == 0)
                return false;
            num /= 10;
        }
        
        return true;
    }
};