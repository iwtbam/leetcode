// https://leetcode-cn.com/problems/kth-smallest-number-in-multiplication-table/
// kth smallest number in multiplication table
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int hi = m * n, lo = 1, mid = 0;
        int res = 1;        
        
        while(lo < hi){
            mid = (lo + hi) >> 1;
            int num = smaller(m, n, mid);        
            if(num >= k){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
        // for(int i = 1; i <= m; i++){
        //     int index = min(lo, i * n) / i;
        //     res = max(index * i, res);
        // }
        // return res;
    }

    int smaller(int m, int n, int target){
        int count = 0;
        for(int i = 1; i <= m; i++){
            count += min(target, i * n) / i;
        }
        return count;
    }
};