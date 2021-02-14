// https://leetcode-cn.com/problems/sequence-reconstruction/
// sequence reconstruction
class Solution {
    public boolean sequenceReconstruction(int[] org, List<List<Integer>> seqs) {
        
        
        if(org.length == 0)
            return true;
        
        if(seqs.size() == 0)
            return false;
        
        
        
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        Map<Integer, Integer> indegrees  = new HashMap<>();
        Set<Integer> record = new HashSet<>();        
        
        int N = org.length;
        
        for(int i = 1; i <= N; i++)
            indegrees.put(i, 0);
        
        boolean update = false;
        
        for(List<Integer> seq : seqs){
      
            if(seq.size() != 0)
                update = true;
            if(seq.size() == 0)
                continue;
            
            int node = seq.get(0);
            if(node > org.length || node < 1)
                return false;
            
            for(int i = 1; i < seq.size(); i++){
               
                int pre = seq.get(i - 1);
                int cur = seq.get(i);
                
                if(pre > org.length || cur > org.length || pre < 1 || cur < 1)
                    return false;
                
                if(!graph.containsKey(pre))
                    graph.put(pre, new HashSet<Integer>());
                
                if(!graph.get(pre).contains(cur))
                    indegrees.put(cur, indegrees.get(cur) + 1);
                
                graph.get(pre).add(cur);
            }
        }
        
        if(!update)
            return false;
        
        Queue<Integer> q = new LinkedList<>();
        
        for(int i = 1; i <= N; i++){
            Integer val = indegrees.get(i);
            // System.out.println(i + " " + val);
            if(val == 0)
                q.offer(i);
        }
            
        List<Integer> res = new ArrayList<>();
        
        while(q.size() == 1){
            
            int key = q.poll();
            res.add(key);
            // System.out.println(key);
            Set<Integer> old = graph.get(key);
            indegrees.remove(key);
            
            if(old!=null){
                for(int node : old){
                    int degree = indegrees.get(node) - 1;
                    if(degree == 0)
                        q.offer(node);
                    indegrees.put(node, degree);
                }
            }
        
        }
        
        return res.size() == org.length;
    }
}