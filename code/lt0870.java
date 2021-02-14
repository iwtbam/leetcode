// https://leetcode-cn.com/problems/advantage-shuffle/
// advantage shuffle
class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        int L = A.length;
        
        Comparator<int[]> cmp = new Comparator<int[]>(){
            public int compare(int[] a , int[] b){
                return b[0] - a[0];
            }
        };
        
        
        
        int[][] AI = new int[L][2];
        int[][] BI = new int[L][2];

        for(int i = 0; i < L; i++){
            AI[i][0] = A[i];
            BI[i][0] = B[i];
            AI[i][1] = i;
            BI[i][1] = i;
        }
        
        Arrays.sort(AI, cmp);
        Arrays.sort(BI, cmp);
        
        int i = 0, j = 0;
        int[] res = new int[L];
        
        Arrays.fill(res, UN_FILLED);
        
        while( i < L && j < L){
            if(AI[i][0] > BI[j][0]){
                res[BI[j][1]] = AI[i][0];
                i++;
            }
            j++;
        }
        j = 0;
        while(i < L){
            if(res[j] == Integer.MAX_VALUE){
                res[j] = AI[i][0];
                i++;
            }
            j++;
        }
        
        
        return res;
    }
    
    
    private final int UN_FILLED = Integer.MAX_VALUE;
}