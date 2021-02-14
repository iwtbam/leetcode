class Solution {
    public int bitwiseComplement(int N) {
        if(N == 0)
            return  1;
        
        int res = 0;
        
        int last = 31;
        
        for(int i = 31; i >= 0; i--){
            if((N & 1 << i) != 0){
                last = i;
                break;
            }
        }
        
        // System.out.println(last);
        
        for(int i = 0; i <=last; i++){
            if((1 << i & N) == 0)
                res |= 1 << i;
        }
        
        return res;
    }
}