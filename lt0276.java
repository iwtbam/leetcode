class Solution {
    public int numWays(int n, int k) {
        
        if(n == 0 || k == 0)
            return 0;       
        
        if(n > 2 && k == 1)
            return 0;
        
        int different_color = k , same_color = 0;
        
        for(int i = 1; i < n; i++){
            int pre_same_color = same_color;
            same_color = different_color ;
            different_color = (different_color + pre_same_color) * (k - 1); 
        }
        
        return different_color + same_color;
        
    }
}