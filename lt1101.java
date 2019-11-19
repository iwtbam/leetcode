import java.util.*;

class Solution {
    public int earliestAcq(int[][] logs, int N) {
        Arrays.sort(logs, (log1, log2)->{
            return log1[0] - log2[0];
        });

        int[] sets  = new int[N];
        int[] ranks = new int[N];

        initUnion(sets);
        Set<Integer> count = new HashSet<>();

        for(int i = 0; i < logs.length; i++){
            merge(sets, ranks, logs[i][1], logs[i][2]);
            count.add(logs[i][1]);
            count.add(logs[i][2]);
            if(count.size() == N && isOne(sets)){
                return logs[i][0];
            }
        }

        return -1;
    }

    public void initUnion(int[] sets){
        for(int i = 0; i < sets.length; i++)
            sets[i] = i;
    }

    public int  parent(int[] sets, int n){
        return sets[n] == n ? n : parent(sets, sets[n]);
    }

    public boolean merge(int[] sets, int[] ranks, int n1, int n2){
        int p1 = parent(sets, n1);
        int p2 = parent(sets, n2);
        if(p1 == p2)
            return false;
        if(ranks[p1] < ranks[p2]){
            sets[p1] = p2;
        }else{
            if(ranks[p1] == ranks[p2])
                ranks[p1]++;
            sets[p2] = p1;
        }
        return true;
    }

    public boolean isOne(int[] sets){
        Set<Integer> count = new HashSet<>();
        for(int i = 0; i < sets.length; i++){
            count.add(parent(sets, i));
        }
        return count.size() <= 1;
    }
}