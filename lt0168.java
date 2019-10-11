class Solution {
    public String convertToTitle(int n) {
        StringBuffer sb = new StringBuffer();
        while(n!=0){
            int offset = (n - 1)% 26; 
            sb.append((char)('A' + offset));
            n = (n - 1) / 26;
        }
        
        return sb.reverse().toString();
    }
}