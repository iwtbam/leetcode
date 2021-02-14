// https://leetcode-cn.com/problems/parallel-courses/
// parallel courses
import java.util.*;

class Solution {
    public int minimumSemesters(int N, int[][] relations) {
        int[] indegrees = new int[N + 1];
        ArrayList<Integer>[] graph = new ArrayList[N + 1]; 
        for(int i = 0; i < N + 1; i++)
            graph[i] = new ArrayList<>();

        boolean[] vis = new boolean[N + 1];
        
        for(int[] relation : relations){
            indegrees[relation[1]]++;
            graph[relation[0]].add(relation[1]);
        }

        
        int count = 0;
        int num = 0;
        
        while(num < N){
            List<Integer> nodes = new ArrayList<>();
            
            for(int i = 1; i < indegrees.length; i++){
                if(vis[i] || indegrees[i] > 0)
                    continue;
                nodes.add(i);
                vis[i] = true;
            }

            if(nodes.size() == 0)
                break;

            for(int node : nodes){
                List<Integer> nexts = graph[node];
                for(int next : nexts)
                    indegrees[next]--;
            }

            num += nodes.size();
            count++;
        }
        
        return num < N ? -1 : count;
    }
    
}