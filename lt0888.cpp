// https://leetcode-cn.com/problems/fair-candy-swap/
// fair candy swap
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int diff = accumulate(B.begin(), B.end(), 0) -  accumulate(A.begin(), A.end(), 0);
        size_t n = A.size();
        for(int i = 0; i < n; i++){
            auto pos = lower_bound(B.begin(), B.end(), A[i] + diff / 2);
            if(binary_search(B.begin(), B.end(), A[i] + diff / 2))
                return {A[i], A[i] + diff / 2};
        }

        return {0, 0};
    }
};