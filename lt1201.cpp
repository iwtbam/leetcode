// https://leetcode-cn.com/problems/ugly-number-iii/
// ugly number iii
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        
        long long lcm_ab  = lcm(a, b);
        long long lcm_bc  = lcm(b, c);
        long long lcm_ac  = lcm(a, c);
        long long lcm_abc = lcm(lcm_ab, c);

        long long lo = 1;
        long long hi = 2 * pow(10, 9);

        // cout << lcm_ab << " " << lcm_bc << " " << lcm_ac << " " << lcm_abc << endl;
        
        while(lo <= hi){
            long long mid = (lo + hi) >> 1;
            long long ugly_number = mid / a + mid / b + mid / c - mid / lcm_ab - mid / lcm_bc - mid / lcm_ac + mid / lcm_abc;
            // if(ugly_number == n)
            //     return mid;
            if(ugly_number < n)
                lo = mid + 1;
            else 
                hi = mid - 1;
        }

        return lo;
    }

    long long gcd(long long a, long long b){
        return a%b == 0 ? b : gcd(b, a%b);
    }

    long long lcm(long long a, long long b){
        return a * b / gcd(a, b);
    }
};