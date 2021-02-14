class Solution {
    public String removeDuplicates(String s, int k) {
        if(k == 1)
            return new String();
        
        String pre = s;
        String res = cut(s, k);
        
        while(res.length() != pre.length()){
            pre = res;
            res = cut(res, k);
        }
        
        return res;
    }
    
    public String cut(String s, int k){
        StringBuffer sb = new StringBuffer();
        int index = 1, c = 1;
        
        while(index  < s.length()){
            if(s.charAt(index) == s.charAt(index - 1))
                c++;
            else{
                sb.append(s.substring(index - c, index));
                c = 1;
            }
            
            if(c == k){
                c = 1;
                index = index + 1;
            }
            
            index++;
                
        }
        
        if(index > s.length())
            return sb.toString();
        sb.append(s.substring(index - c, index));
        return sb.toString();
    }
}