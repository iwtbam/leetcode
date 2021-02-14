class Solution {
    public int smallestCommonElement(int[][] mat) {
        Set<Integer> record = new HashSet<Integer>();
        Set<Integer> temp = new HashSet<Integer>();
        int rows = mat.length;
        if(rows == 0)
            return 0;
        
        int cols = mat[0].length;

        for(int i = 0; i < cols; i++)
            record.add(mat[0][i]);
            
        for(int i = 1; i < rows; i++){
            if(record.size() == 0)
                return -1;
            Set<Integer> res = new HashSet<Integer>();
            for(int  j = 0; j < cols; j++){
                if(record.contains(mat[i][j]))
                    res.add(mat[i][j]);
            }
            
            record = res;
        }
        
        int rval = Integer.MAX_VALUE;
        
        for(int val : record){
            rval = Math.min(rval, val);
        }
        
        
        
        return rval == Integer.MAX_VALUE ? -1 : rval;
    }
}