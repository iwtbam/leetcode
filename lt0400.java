class Solution {
    public int findNthDigit(int n) {
        if(n < 10)
            return n;
        
        long len = 0, num = 9;
        int bit = 1;
        while(len + bit * num < n){
            len += bit * num;
            bit = bit + 1;
            num = num * 10;
        }
    
        long cur = (long)Math.pow(10, bit - 1) + (n - len - 1) / bit;    
        int index = (int)(n - len - 1) % bit;
        String strN = String.valueOf(cur);
        return strN.charAt(index) - '0';
    }
}