import java.util.*;

class Solution {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        Map<Integer, Set<Integer>> nexts = new HashMap<>();
        int size = pid.size();
     
        for(int i = 0; i < size; i++){
            if(!nexts.containsKey(ppid.get(i)))
                nexts.put(ppid.get(i), new HashSet<Integer>());   
            nexts.get(ppid.get(i)).add(pid.get(i));
        }
        
        List<Integer> res = new ArrayList<>();
        res.add(kill);
        
        int left = 0, right = 0;
        while(left <= right){
            for(int cur = left; cur <= right; cur++){
                int parentId = res.get(cur);
                Set<Integer> childs = nexts.get(parentId);
                
                if(childs == null)
                    continue;
                
                for(int childId: childs){
                    res.add(childId);   
                }
            }
            
            left  = right + 1;
            right = res.size() - 1;
        }
        
        return res;
    }
}