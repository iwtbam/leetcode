class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int len = deck.length;
        int[] hash = new int[10001];
        
        for(int num : deck)
            hash[num]++;
        
        int X = -1;
        
        for(int i = 0; i < len; i++){
            if(hash[i]!=0){
               if(X == -1)
                   X = hash[i];
               else
                   X = gcd(X, hash[i]);
            }
        }
        
      
        return X >= 2;
    }
    
    public int gcd(int a, int b){
        return a == 0 ? b : gcd(b%a, a);
    }
}