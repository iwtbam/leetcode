import java.util.*;


class Solution {
    public List<Integer> addToArrayForm(int[] A, int K) {
        int len1 = A.length;
        String num = String.valueOf(K);
        int len2 = num.length();
        int left = len1 - 1, right = len2 - 1;
        int co = 0;
        List<Integer> res = new ArrayList<>();
        while(left >= 0 || right >= 0 || co > 0){
            int n1 = left >= 0 ? A[left] : 0;
            int n2 = right >= 0 ? num.charAt(right) - '0' : 0;
            int val = n1  + n2 + co;
            co  = val / 10;
            val = val % 10;
            left--;
            right--;
            res.add(val);
        }
        
        Collections.reverse(res);
        return res;
    }
}