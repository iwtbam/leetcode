// https://leetcode-cn.com/problems/reordered-power-of-2/
// reordered power of 2
class Solution {
    public boolean reorderedPowerOf2(int N) {
        int[] h = hash(N);
        
        int[][] lookUp = getLookUp();
        
        for(int i = 0; i < 31; i++){
            if(equal(h, lookUp[i]))
                return true;
        }
        
        return false;
    }
    
    public int[] hash(int N){
        int[] h = new int[10];
        while(N > 0){
            h[N % 10]++;
            N /= 10;
        }
        return h;
    }
    
    public boolean equal(int[] h1, int[] h2){
        for(int i = 0; i < 10; i++){
            if(h1[i] != h2[i])
                return false;
        }
        
        return true;
    }
    
    public int[][] getLookUp(){
        int[][] lookUp = new int[32][];
        for(int i = 0; i < 32; i++){
            lookUp[i] = hash((int)Math.pow(2, i));    
        }
        return lookUp;
    } 
}