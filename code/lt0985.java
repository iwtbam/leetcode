// https://leetcode-cn.com/problems/sum-of-even-numbers-after-queries/
// sum of even numbers after queries
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int L = A.length;
        int qL = queries.length;
        
        int sum = 0;
        for(int i = 0; i < L; i++){
            if(A[i] % 2 == 0)
                sum += A[i];
        }
        
        int[] res = new int[qL];
        
        for(int i = 0; i < qL; i++){
            int[] query = queries[i];
            
            int val   = query[0];
            int index = query[1];
            
            if(Math.abs(val) % 2 == 1){
                if(Math.abs(A[index]) % 2 == 1)
                    sum += A[index] + val;
                else{
                    sum -= A[index];
                }
            }else{
                if(A[index] % 2 == 0)
                    sum += val;
            }
            
            A[index] = A[index] + val;
            res[i] = sum;
        }
        
        return res;
    }
}