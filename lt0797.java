import java.util.*;

class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        return findPath(graph, 0, graph.length - 1);
    }
    
    public List<List<Integer>> findPath(int[][] graph, int src, int dst){
        
        List<List<Integer>> res = new LinkedList<>();
        List<Integer> dsts = new LinkedList<>();
        
        if(graph[src] == null){
            return res;
        }
        
        if(src == dst){
            dsts.add(dst);
            res.add(dsts);
            return res;
        }
        
        for(int i = 0; i < graph[src].length; i++){
            List<List<Integer>> temp = findPath(graph, graph[src][i], dst);
            if(temp.size() == 0)
                continue;
            for(List<Integer> l : temp){
                l.add(0, src);
                res.add(l);
            }
        }
        
        return res;
    }
}