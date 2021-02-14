// https://leetcode-cn.com/problems/route-between-nodes-lcci/
// route between nodes lcci
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<unordered_set<int>> adj(n);
        vector<int> vis(n, 0);
        size_t size = graph.size();
        for(int i = 0; i < size; i++){
            auto e = graph[i];
            adj[e[0]].insert(e[1]);
        }

        queue<int> q;

        q.push(start);

        while(q.size()){
            int front = q.front();
            q.pop();

            auto nodes = adj[front];
            for(int node : nodes){
                if(node == target)
                    return true;
                if(vis[node])
                    continue;
                vis[node] = 1;
                q.push(node);
            }
        }
        return false;
    }
};