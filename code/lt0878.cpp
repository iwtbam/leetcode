// https://leetcode-cn.com/problems/nth-magical-number/
// nth magical number
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long long l = 1, r = static_cast<long long>(N) * max(A, B);
        const int MOD = pow(10, 9) + 7;
        int C = lcm<int, int>(A, B);
        while(l < r){
            long long mid = l + (r - l) / 2;
            long long num = mid / A + mid / B - mid / C;
            if(num < N){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l % MOD;
    }

};