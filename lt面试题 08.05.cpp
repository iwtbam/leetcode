// https://leetcode-cn.com/problems/recursive-mulitply-lcci/
// recursive mulitply lcci
class Solution {
public:
    
    int multiply(long long A, int B){
        if(B == 0)
            return 0;

        if((B & 1) == 1)
            return A + multiply(A + A, B >> 1);
        
        return multiply(A + A, B >> 1);
    }

    int multiply(int A, int B) {
        return multiply(static_cast<long long>(A), B);
    }
};