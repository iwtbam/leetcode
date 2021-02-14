// https://leetcode-cn.com/problems/confusing-number-ii/
// confusing number ii
class Solution {
    public int confusingNumberII(int N) {
          
        int[] rotates = new int[]{0, 1, 6, 8, 9};
        helper(0, N, rotates);
        return ans;
    }
    
    public void helper(long cur, int N, int[] rotates){
        
        if(cur > Integer.MAX_VALUE)
            return;
        
        if(cur > N)
            return;
        
        if(check((int)cur))
            ans++;
 
        
        for(int i = 0; i < rotates.length; i++){
            long next = cur * 10 + rotates[i];
            if(next == 0)
                continue;
            helper(next, N, rotates);
        }
            
    }
    
    public boolean check(int num){
        int rnum = 0;
        int old = num;
        while(num!=0){
            rnum = rnum * 10 + map[num % 10];
            num = num / 10;
        }
        
        return old != rnum;
    }
    
    private int ans = 0;
    private int[] rotates = new int[]{0, 1, 6, 8, 9};
    private int[] map = new int[]{0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
}