// 带 rank 优化 果然很强
class Solution {

    public boolean validTree(int n, int[][] edges) {
        int[] sets = new int[n];
        int[] rank = new int[n];
        for(int i = 0; i < n; i++)
            sets[i] = i;
        
        for(int[] edge : edges){
            if(!union(sets, rank, edge[0], edge[1]))
                return false;
        }
        
        int p = parent(sets, 0);
        
        for(int i = 1; i < n; i++)
            if(p != parent(sets, i))
                return false;
        return true;
    }
    
    public int parent(int[] sets, int node){
        return node == sets[node] ? node : parent(sets, sets[node]);
    }
    
    public boolean union(int[] sets, int[] rank ,int n1, int n2){
        int p1 = parent(sets, n1);
        int p2 = parent(sets, n2);
        
        if(p1 == p2)
            return false;
        
        if(sets[p1] < sets[p2])
            sets[p1] = p2;
        else{
            sets[p2] = p1;
            if(rank[p2] == rank[p1])
                rank[p1]++;
        }
        
        return true;
    }
}


// class Solution {
//     public boolean validTree(int n, int[][] edges) {
//         int[] sets = new int[n];
//         for(int i = 0; i < n; i++)
//             sets[i] = i;
//         for(int[] edge : edges){
//             int p1 = parent(sets, edge[0]);
//             int p2 = parent(sets, edge[1]);
//             if(p1 == p2)
//                 return false;
//             sets[p1] = p2;
//         }
//         int p = parent(sets, 0);
//         for(int i = 1; i < n; i++)
//             if(p != parent(sets, i))
//                 return false;
//         return true;
//     }
//     public int parent(int[] sets, int node){
//         return node == sets[node] ? node : parent(sets, sets[node]);
//     }
// }