class Solution {
    public int numPrimeArrangements(int n) {
        
        
        if(n <= 1)
            return 1;
        
        int[] primes = new int[n + 1];
        
        primes[1] = 1;
        primes[2] = 0;
        int count = 0;
        for(int i = 2; i <=n; i++){
            if(primes[i] == 1)
                continue;
            count++;
            for(int j = 1; j * i <= n; j++){
                primes[j*i] = 1;
            }
        }
        
        return fac(n, count); 
    }
    
    public int fac(int n, int count){
        
        long res = 1;
        
        for(int i = 1; i <= count; i++)
            res = (res * i) % mod;
        
        for(int i = 1; i <= n - count; i++)
            res = (res * i) % mod;
        
        return (int)res;
    }
    
    private int mod = (int)Math.pow(10, 9) + 7;
    
}