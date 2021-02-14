// https://leetcode-cn.com/problems/minimum-swaps-to-make-sequences-increasing/
// minimum swaps to make sequences increasing
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int size = A.size();
        vector<int> keep(size, INT_MAX);
        vector<int> swap(size, INT_MAX);

        keep[0] = 0;
        swap[0] = 1;

        for(int i = 1; i < size; i++){
            if(A[i] > A[i - 1] && B[i] > B[i - 1]) {
                keep[i] = keep[i - 1];
                swap[i] = swap[i - 1] + 1;
            }

            if(A[i] > B[i - 1] && B[i] > A[i - 1]){
                keep[i] = min(keep[i], swap[i - 1]);
                swap[i] = min(swap[i], keep[i - 1] + 1);
            }
        }

        return min(keep[size - 1], swap[size - 1]);
    }
};