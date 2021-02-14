import java.util.*;

class Solution {
    public int[] prisonAfterNDays(int[] cells, int N) {
        
        int[] next = new int[cells.length];
        int[] pre  = cells;
        int len = cells.length;
        Set<Integer> memos = new HashSet<Integer>();
        List<Integer> record = new ArrayList<Integer>();
        for(int i = 0; i < N; i++){
            for(int j = 1; j < len - 1; j++)
                next[j] = (pre[j - 1] ^ pre[j + 1]) == 0 ? 1 : 0;
            System.arraycopy(next, 0, pre, 0, 8);
            
            int key = toKey(pre);
            if(memos.contains(key))
                break;
            memos.add(key);
            record.add(key);
        }
        
        if(record.size() == N)
            return next;
        
        
        return toVal(record.get((N - 1) % record.size()));
       
    }
    
    public Integer toKey(int[] arrs){
        int key = 0;
        for(int i = 0; i < 8; i++){
            key = key | (arrs[i] << i);
        }
        return key;
    }
    
    public int[] toVal(int key){
        int[] arrs = new int[8];
        for(int i = 0; i < 8; i++){
            arrs[i] = (key & 1 << i) >> i;
        }
        
        return arrs;
    }
}