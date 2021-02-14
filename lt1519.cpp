// https://leetcode-cn.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
// number of nodes in the sub tree with the same label
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n, vector<int>());
        size_t size = edges.size();
        for(int i = 0; i < size; i++){
            auto& edge = edges[i];
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);

        }
        
        vector<int> ans(n, 0);
        vector<int> vis(n, 0);

        
       solve(0, graph, ans, labels, vis);
        
        return ans;
        
    }
    
    vector<int> solve(int node, vector<vector<int>>& graph, vector<int>& ans, string& labels, vector<int>& vis){
        
        int size = graph[node].size();
        vector<int> record(26, 0);
        vis[node] = 1;
        for(int i = 0; i < size; i++){
            if(vis[graph[node][i]])
                 continue;
           
            auto child = solve(graph[node][i], graph, ans, labels,vis);
            for(int i = 0; i < 26; i++){
                record[i] += child[i];
            }
        }
        
        int key = labels[node] - 'a';
        
        record[key] = record[key] + 1;
        ans[node] = record[key];
    
        return move(record);
    }
};