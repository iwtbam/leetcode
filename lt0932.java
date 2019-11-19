import java.util.*;

class Solution {
    public int[] beautifulArray(int N) {
        int[] arrs = new int[N];
        for(int i = 0; i < N; i++)
            arrs[i] = i + 1;
        divide(arrs, 0, N);
        return arrs;
    }
    
    public void divide(int[] arrs, int start, int end){
        
        if(end - start <= 2)
            return;
        
        int oL =  (end - start + 1) / 2;
        int eL =  (end - start) / 2;
        
        int[] odds =  new int[oL];
        int[] evens = new int[eL];
        
        for(int i = 0; i < end - start; i++){
            if(i % 2 == 1)
                evens[i/2] = arrs[start + i];
            else
                odds[i/2]  = arrs[start + i];
        }
        
        System.arraycopy(odds, 0, arrs, start, oL);
        System.arraycopy(evens, 0, arrs, start + oL, eL);
        
        divide(arrs, start, start + oL);
        divide(arrs, start + oL, end);
    }
}