// https://leetcode-cn.com/problems/grumpy-bookstore-owner/
// grumpy bookstore owner
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int maxPro = 0;
        int len = customers.length;
        for(int i = 0; i < len; i++){
            maxPro += grumpy[i] == 0 ? customers[i] : 0;
        }
        
        // System.out.println(maxPro);
        
        int dPro = 0;
        for(int i = 0; i< X; i++){
            if(grumpy[i] == 1)
                dPro += customers[i];
        }
        
        int maxDPro = dPro;
        for(int i = X; i < len; i++){
            dPro = dPro + (grumpy[i] == 1 ? customers[i] : 0) - (grumpy[i - X] == 1 ? customers[i - X] : 0);
            maxDPro = Math.max(maxDPro, dPro);
        }
        
        return maxPro + maxDPro;
    }
}