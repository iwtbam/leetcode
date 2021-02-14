// https://leetcode-cn.com/problems/preimage-size-of-factorial-zeroes-function/
// preimage size of factorial zeroes function
class Solution {
public:
    int preimageSizeFZF(int K) {
        return ubound(K)  - lbound(K) + 1;
    }

    int lbound(int K){
        long long l = 0, r = 1e10;
        while(l < r){
            long long mid = (l + r) >> 1;

            if(zero(mid) >= K){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }

    int ubound(int K){
        long long l = 0, r = 1e10;
        while(l < r){
            long long mid = (l + r + 1) >> 1;
            if(zero(mid) <= K){
                l = mid;
            }else{
                r  = mid - 1;
            }
        }
        return l;
    }

    int zero(long long n){
        int res = 0;
        while(n / 5){
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};