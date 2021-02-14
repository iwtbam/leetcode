class Solution {
    public int smallestFactorization(int a) {       
        if(a < 10)
            return a;
        int e = 0;
        long res = 0;
        while(a!=1){
            int i = 9;
            while(i >= 2){
                if(a % i == 0){
                    a = a / i; 
                    
                    res = res + (long)Math.pow(10, e++) * i;
                    if(res  > Integer.MAX_VALUE)
                        return 0;
                    
                    break;
                }
                i--;
            }
            
            if(i == 1 && a > 10)
                return 0;
        }
        
        return (int)res;
    }
}