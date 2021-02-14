// https://leetcode-cn.com/problems/convert-to-base-2/
// convert to base 2
class Solution {
    public String baseNeg2(int N) {
        if(N == 0)
            return "0";
        
        StringBuffer sb = new StringBuffer();
        while(N != 0){
            sb.append(Math.abs(N) % 2);
            N = (int)Math.ceil(N / -2.0);
        }
        return sb.reverse().toString();
    }
}