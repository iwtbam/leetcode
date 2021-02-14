# https://leetcode-cn.com/problems/path-with-maximum-probability/ 
# path with maximum probability 
import heapq as hq

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float: 
        graph = [[] for i in range(n)]
        
        for prob, edge in zip(succProb, edges):
            graph[edge[0]].append([prob, edge[1]])
            graph[edge[1]].append([prob, edge[0]])
        
        vis = [0 for _ in range(n)]
        dis = [0 for _ in range(n)]
        q = []

        hq.heappush(q, [-1.0, start])
        dis[start] = 1.0

        while len(q) :
            while len(q) and vis[q[0][1]]:
                hq.heappop(q)
            if len(q) == 0:
                break
            
            _, node = hq.heappop(q)
            
            for p, e in graph[node]:
                if p * dis[node] > dis[e]:
                    dis[e] = p * dis[node]
                    hq.heappush(q, [-dis[e], e])
            vis[node] = 1

        return dis[end]