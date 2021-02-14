import java.util.*;

class Solution {
    
    class Frac {
        public int a;
        public int b;
        
        public Frac(int a, int b){
            this.a = a;
            this.b = b;
        }
        
        public boolean equals(Object o){
            Frac f = (Frac)o;
            return a == f.a && b == f.b;
        }
        
        public int hashCode(){
            return a << 16 | b;
        }
    }
    
    public int maxPoints(int[][] points) {
        int len = points.length;
        
        if(len <= 1)
            return len;

        int maxCount = 0;
        for(int i = 0; i < len; i++){
            Map<Frac, Integer> record = new HashMap<>();
            record.put(new Frac(0,0), 0);
            int extra = 0;
            for(int j = i + 1; j < len; j++){
                int a = points[i][0] - points[j][0];
                int b = points[i][1] - points[j][1];
                int num = gcd(a, b);
                
                if(num == 0){
                    extra++;
                    continue;
                }
                
                a = a / num;
                b = b / num;
                if(a == 0)
                    b = 1;

                if(b == 0)
                    a = 1;

                int kNum = record.getOrDefault(new Frac(a, b), 0);
                record.put(new Frac(a, b), kNum + 1);
                
            }
            
            for(int k : record.values())
                maxCount = Math.max(maxCount, extra + k);
        }
        
        return maxCount + 1;
    }
    
    public int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
}