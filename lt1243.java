import java.util.*;

class Solution {
    public List<Integer> transformArray(int[] arr) {
        int len = arr.length;
        int[] pre = arr;
        int[] cur = new int[len];
        cur[0] = pre[0];
        cur[len - 1] = pre[len - 1];
        boolean isChange = true;
        while(isChange){
            isChange = false;
            for(int i = 1; i < len - 1; i++){
                cur[i] = pre[i];
                if(pre[i] > pre[i - 1] && pre[i] > pre[i + 1])
                    cur[i] = pre[i] - 1;
                
                if(pre[i] < pre[i - 1] && pre[i] < pre[i + 1])
                    cur[i] = pre[i] + 1;
                
                isChange = isChange || cur[i] != pre[i];
               
            }
            
            System.arraycopy(cur, 0, pre, 0, len);
        
        }
        
        List<Integer> res = new ArrayList<>();
        
        for(int i = 0; i < len; i++)
            res.add(cur[i]);
        
        return res;
    }
}