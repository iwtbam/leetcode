import java.util.*;

class Solution {
    public int removeStones(int[][] stones) {
        int[] sets = new int[20000];
        int[] rank = new int[20000];
        
        Set<Integer> record = new HashSet<>();
        
        for(int i = 0; i < sets.length; i++)
            sets[i] = i;
        
        for(int[] stone : stones){
            union(sets, rank, stone[0], stone[1] + 10000);
            record.add(stone[0]);
            record.add(stone[1] + 10000);
        }
        
        Set<Integer> nodes = new HashSet<>();
        for(Integer ele : record){
            nodes.add(parent(sets, ele));
        }
        
        return stones.length - nodes.size();
        
        
    }
    
    public int parent(int[] sets, int n){
        return sets[n] == n ? n : parent(sets, sets[n]);
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
            if(rank[p1] == rank[p2])
                rank[p1]++;
        }
        
        return true;
        
    }
    
}