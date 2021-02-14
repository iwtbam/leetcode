class Solution {
    public int minCostII(int[][] costs) {
        int n = costs.length;
        
        if(n == 0)
            return 0;
        int k = costs[0].length;
        
        if(k == 0)
            return 0;
        
        int[] cur = new int[k];
        int[] next = new int[k];
        
        System.arraycopy(costs[0], 0, cur, 0, k);
        
        int minI = 0, minI2 = -1;
        
        for(int i = 1; i < k; i++){
            
            if(minI2 == -1 || cur[i] < cur[minI2])
                minI2 = i;
            
            if(cur[i] < cur[minI]){
                minI2 = minI;
                minI = i;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < k; j++){
                if(j == minI){
                    next[j] = cur[minI2];
                }else{
                    next[j] = cur[minI];
                }
               
                
                next[j] = next[j] + costs[i][j];
            }
            System.arraycopy(next, 0, cur, 0, k);
            
            minI = 0;
            minI2 = -1;
            
            for(int j = 1; j < k; j++){
                
                if(minI2 == -1 || cur[j] < cur[minI2]){
                    minI2 = j;
                }
                
                
                if(cur[j] < cur[minI]){
                    minI2 = minI;
                    minI = j;
                }
                
              
            }
           
        }
    
        return cur[minI];
    }
}