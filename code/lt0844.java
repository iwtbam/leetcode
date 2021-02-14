class Solution {
    public boolean backspaceCompare(String S, String T) {
        String nS = deal(S);
        String nT = deal(T);
        return nS.equals(nT);
    }
    
    public String deal(String str){
        StringBuffer sb = new StringBuffer();
        int L = str.length();
        for(int i = 0; i < L; i++){
            char c = str.charAt(i);
            if(c == '#' ){
                if(sb.length() != 0)
                    sb.deleteCharAt(sb.length() - 1);
            }
            else
                sb.append(c);
        }
        return sb.toString();
    }
}