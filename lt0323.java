import java.util.*;

class Solution {
    public int countComponents(int n, int[][] edges) {
        int[] rank = new int[n];
        int[] sets = new int[n];
        
        for(int i = 0; i < n; i++)
            sets[i] = i;
        
        for(int[] edge : edges){
            union(sets, rank, edge[0], edge[1]);
        }
        
        Set<Integer> parents = new HashSet<>();
        
        for(int i = 0; i < n; i++)
            parents.add(parent(sets, i));
        
        return parents.size();
    }
    
    public boolean union(int[] sets, int[] rank, int n1, int n2){
        int p1 = parent(sets, n1);
        int p2 = parent(sets, n2);
        
        if(p1 == p2)
            return false;
        
        if(rank[p1] < rank[p2])
            sets[p1] = p2;
        else{
            sets[p2] = p1;
            if(p1 == p2)
                rank[p1]++;
        }
        
        return true;
    }
    
    public int parent(int[] sets, int n){
        return sets[n] == n ? n : parent(sets, sets[n]);
    }
    
    
}