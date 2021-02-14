// https://leetcode-cn.com/problems/hexspeak/
// hexspeak
class Solution {
    public String toHexspeak(String num) {
        long n = Long.valueOf(num);
        Set<Character> valids = new HashSet<>();
        StringBuffer res = new StringBuffer();
        while(n > 0){
            char c = tables[(int)(n % 16)];
            if(c == '0')
                c = 'O';
            if(c == '1')
                c = 'I';
            
            // System.out.println(c);
            if(c >= '0' && c <= '9')
                return "ERROR";
            
            n = n / 16;
            res.append(c);
        }
        
        return res.reverse().toString();
    }
    
    private final char[] tables = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
}