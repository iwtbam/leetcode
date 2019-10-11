import java.util.*;

class Solution {
    public int findCircleNum(int[][] M) {
        int N = M.length;
        if(N == 0)
            return 0;
        int[] sets = new int[N];
        int[] rank = new int[N];
        for(int i = 0; i < N; i++)
            sets[i] = i;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(M[i][j] == 1)
                    union(sets, rank, i, j);
            }
        }
        
        Set<Integer> parents = new HashSet<>();
        for(int i = 0 ; i < N; i++)
            parents.add(parent(sets, i));
        
        return parents.size();
    }
    
    public int parent(int[] sets, int n){
        return sets[n] == n ? n : parent(sets, sets[n]);
    }
    
    public boolean union(int[] sets, int[] rank, int n1, int n2){
        if(n1 == n2)
            return false;
        
        int p1 = parent(sets, n1);
        int p2 = parent(sets, n2);
        if(p1 == p2)
            return false;
        if(rank[p1] < rank[p2])
            sets[p2] = p1;
        else{
            sets[p1] = p2;
            if(rank[p1] == rank[p2])
                rank[p2]++;
        }
        
        return true;
    }
}