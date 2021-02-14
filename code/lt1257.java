import java.util.*;

class Solution {
    public String findSmallestRegion(List<List<String>> regions, String region1, String region2) {
        
        Map<String, String> graph = new HashMap<>();
        
        for(List<String> region : regions){
            String parent = region.get(0);
            int size = region.size();
            for(int i = 1; i < size; i++)
                graph.put(region.get(i), parent);
        }
        
        Set<String> ps = new HashSet<>();
        ps.add(region1);
        String node = region1;
        while(graph.containsKey(node)){
            node = graph.get(node);
            ps.add(node);
        }
        
        if(ps.contains(region2))
            return region2;
        
        node = region2;
        while(graph.containsKey(node)){
            node = graph.get(node);
            if(ps.contains(node))
                return node;
        }
        
        return null;
    }
}