// https://leetcode-cn.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/
// minimum degree of a connected trio in a graph
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<bitset<500>> graph(n + 1);
        vector<int> degree(n + 1);
        int e = edges.size();
        
        for(int i = 0; i < e; i++){
            
            int f = edges[i][0], t = edges[i][1];
            graph[f].set(t, 1);
            graph[t].set(f, 1);
            ++degree[f];
            ++degree[t];
        }
        
        int ans = INT_MAX;
        
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(!graph[i].test(j))
                    continue;
                auto s1 = graph[i] & graph[j];
                for(int k = j + 1; k <= n; k++){
                    if(!s1.test(k))
                        continue;
                    
                    ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                    if(ans == 0)
                        return 0;
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
    
};