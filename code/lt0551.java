class Solution {
    public boolean checkRecord(String s) {
        int c1 = 0, c2 = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i)=='A')
                c1++;
            
            if(s.charAt(i)=='L')
                c2++;
            else
                c2 = 0;
            
            if(c1 > 1 || c2 > 2)
                return false;
            
        }
        
        return true;
    }
}