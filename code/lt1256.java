class Solution {
    public String encode(int num) {
        if(num == 0)
            return "";
        
        int bit = (int)(Math.log(num + 1) / Math.log(2));
        int diff = num - (int)(Math.pow(2, bit) - 1);
        
        char[] res = new char[bit];
        
        for(int i = 0; i < bit; i++){
            res[i] = (char)(((diff & (1 << i)) == 0 ? 0 : 1) + '0');
        }
        
        StringBuffer sb = new StringBuffer();
        for(int i = bit - 1; i >=0; i--){
            sb.append(res[i]);
        }
        
        return sb.toString();
    }
}