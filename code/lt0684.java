class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        
        int len = edges.length;
        int[] sets = new int[len+1];
        for(int i = 0; i <= len; i++)
            sets[i] = i;
        
        int[] res = null;
        
        for(int i = 0; i < len; i++){
            int p1 = find(sets, edges[i][0]);
            int p2 = find(sets, edges[i][1]);
            if(p1 == p2)
                res = edges[i];
            else
                sets[p1] = p2;
        }
        
        return res;
    }
    
    int find(int[] sets, int node){
        while(sets[node]!=node){
            node = sets[node];
        }
        return node;
    }
}