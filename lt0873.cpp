// https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/
// length of longest fibonacci subsequence
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int size = A.size();
        
        unordered_set<int> s;
        for(int i = 0; i < size; i++){
            s.insert(A[i]);
        }

        int res = 0;
        for(int i = 0; i < size - 1; i++){
            for(int j = i + 1; j < size; j++){
                int one = A[i];
                int two = A[j];
                int ans = 0;
                while(s.count(one + two) == 1){
                    int sum = one + two;
                    one = two;
                    two = sum;
                    ans++;
                }
                res = max(res, ans);
            }
        }
        
        return res == 0 ? res : res + 2;
    }
};