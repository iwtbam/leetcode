import java.util.*;

class Solution {
    public int minimumCost(int N, int[][] connections) {
        int len = connections.length;
        if(len < N - 1)
            return -1;
        int[] sets = new int[N + 1];
        for(int i = 0; i <= N; i++)
            sets[i] = i;
        
        int cost = 0;
        Arrays.sort(connections, new Comparator<int[]>(){
           public int compare(int[] a, int[] b){
               return a[2] - b[2];
           }
        });
        
        for(int[] con : connections){
            int p1 = parent(sets, con[0]);
            int p2 = parent(sets, con[1]);
            if(p1 == p2)
                continue;
            cost += con[2];
            sets[p1] = p2;
        }
        
        int p = parent(sets, 1);
        
        for(int i = 2;  i <= N; i++){
            if(p != parent(sets, i))
                return -1;
        }
        
        return cost;
    }
    
    public int parent(int[] sets, int node){
        return node == sets[node] ? node : parent(sets, sets[node]);
    }
}