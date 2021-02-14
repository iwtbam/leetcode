// https://leetcode-cn.com/problems/sort-array-by-parity/
// sort array by parity
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int temp = A[0];

        int i = 0, j = A.size() - 1;
        while(i < j){
            while(i < j && A[j] % 2 != 0){
                j--;
            }
            A[i] = A[j];

            while(i < j && A[i] % 2 == 0){
                i++;
            }

            A[j] = A[i];
        }
        A[i] = temp;
        return A;
    }
};