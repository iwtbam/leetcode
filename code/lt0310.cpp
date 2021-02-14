// https://leetcode-cn.com/problems/minimum-height-trees/
// minimum height trees
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        
        vector<int> degree(n);
        size_t size = edges.size();

        memset(head, 0, sizeof(head));
        memset(next, 0, sizeof(next));
        memset(edge, 0, sizeof(edge));

        tot = 0;

        for(int i = 0; i < size; i++){
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;     
            add_edge(edges[i][0], edges[i][1]);
            add_edge(edges[i][1], edges[i][0]);   
        }

        queue<int> q;

        for(int i = 0; i < n; i++)
            if(degree[i] == 1)
                q.push(i);
        
        while(q.size()){
            if(q.size() == n)
                break;
            size = q.size();
            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();
                for(int j = head[cur]; j ; j = next[j])
                {
                    int node = edge[j];
                    degree[cur]--;
                    degree[node]--;
                    if(degree[node] == 1)
                        q.emplace(node);
                }
            }
            n -= size;
        }

        vector<int> res;

        while(q.size())
        {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }

    void add_edge(int from, int to)
    {
        edge[++tot] = to;
        next[tot] = head[from];
        head[from] = tot;
    }
private:
    int head[20010] = {0};
    int edge[20010] = {0};
    int next[20010] = {0};
    int tot = 0;
};