import java.util.*;

class Solution {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int[] rich : richer){
            if(!graph.containsKey(rich[1]))
                graph.put(rich[1], new ArrayList<>());
            graph.get(rich[1]).add(rich[0]);
        }

        int len = quiet.length;
        int[] answers = new int[len];
        for(int i = 0; i < len; i++)
            answers[i] = dfs(graph, quiet, i);
        return answers;
    }

    public int dfs(Map<Integer, List<Integer>> graph, int[] quiet, int node){
        
        if(memos.get(node)!=null)
            return memos.get(node);
        
        int minQ = node;
        List<Integer> nodes = graph.get(node);
        
        if(nodes != null){
            for(int nextNode : nodes){
                int quietNode = dfs(graph, quiet, nextNode);
                if(quiet[quietNode] < quiet[minQ])
                    minQ = quietNode;
            }
        }

        memos.put(node, minQ);
        return minQ;
    }

    private Map<Integer, Integer> memos = new HashMap<>();
}