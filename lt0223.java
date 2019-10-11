class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int rect1 = (C - A) * (D - B);
        int rect2 = (G - E) * (H - F);
        
        if(C <= E || A >= G || D <= F || B >= H)
            return rect1 + rect2;
        
        int w = Math.min(C, G) - Math.max(A, E);
        int h = Math.min(D, H) - Math.max(B, F);
        
      
        
        return rect1 + rect2 - w * h;
        
    }
}