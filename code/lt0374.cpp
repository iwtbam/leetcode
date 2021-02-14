int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long lo = 1, hi = n;
        while(lo < hi)
        {
            int mid = (lo + hi) / 2;
            int cmp = guess(mid);
            if(cmp==0)
                return mid;
            else if(cmp == -1)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        return lo;
    }
};