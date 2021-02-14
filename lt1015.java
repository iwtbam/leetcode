// https://leetcode-cn.com/problems/smallest-integer-divisible-by-k/
// smallest integer divisible by k
class Solution {
    public int smallestRepunitDivByK(int K) {
        final int LIMIT = Integer.MAX_VALUE;
        Set<Integer> set = new HashSet<Integer>();
        int i = 1, len = 1;
        while(!set.contains(i)){
            if(i % K == 0)
                return len;
            set.add(i);
            i = (i * 10 + 1) % K;
            len++;
        }
        
        return -1;
    }
}