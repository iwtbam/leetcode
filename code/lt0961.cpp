// https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array/
// n repeated element in size 2n array
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int size = A.size();
        vector<int> count(10001, 0);
        for(int i = 0; i < size; i++)
            count[A[i]]++;
        int N = size / 2;
        for(int i = 0; i < size; i++){
            if(count[A[i]] == N)
                return A[i];
        }
        return 0;
            
    }
};