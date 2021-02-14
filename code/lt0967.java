import java.util.*;

class Solution {
    public int[] numsSameConsecDiff(int N, int K) {
        Set<Integer> nums = new HashSet<Integer>();
        for(int i = 1; i <= 9; i++){
            helper(N, K, i, 0, nums);
        }
        
        if(N == 1){
            for(int i = 0; i <= 9; i++)
                nums.add(i);
        }
        
        int[] res = new int[nums.size()];
        
        int i = 0;
        for(int num : nums){
            res[i++] = num;
        }
        
        return res;
    }
    
    public void helper(int N, int K, int n, int num, Set<Integer> nums){
        
        if(n >=10 || n < 0)
            return;
        
        if(N == 0){
            nums.add(num);
            return;
        }
        
        helper(N - 1, K, n + K, num * 10 + n, nums);
        helper(N - 1, K, n - K, num * 10 + n, nums);
    }
}