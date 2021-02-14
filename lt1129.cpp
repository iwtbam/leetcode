// https://leetcode-cn.com/problems/shortest-path-with-alternating-colors/
// shortest path with alternating colors

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        this->node_num = n;
        if(n == 0)
            return {};

        buildGraph(red_edges, blue_edges);
        vector<vector<int>> dis(2, vector<int>(n, -1));
        dis[0][0] = 0;
        dis[1][0] = 0;
        queue<pair<int, int>> q;

        q.emplace(0, 0);
        q.emplace(0, 1);

        while(q.size())
        {
            auto [c, type] = q.front();
            q.pop();
            for(int node = head[1 - type][c]; node; node = next[1 - type][node])
            {
                int n = edge[1 - type][node];
                if(dis[1 - type][n] != -1 && dis[type][c] + 1 > dis[1 - type][n])
                    continue;
                dis[1 - type][n] = dis[type][c] + 1;
                q.emplace(n, 1 - type);
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(dis[0][i] == -1)
                dis[0][i] = dis[1][i];
            else if(dis[1][i] == -1)
                dis[1][i] = dis[0][i];
            dis[0][i] = min(dis[0][i], dis[1][i]);
        } 
      
        return dis[0];
    }


    void buildGraph(vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges)
    {
        size_t rsize = red_edges.size(), bsize = blue_edges.size();
        for(int i = 0; i < rsize; i++)
            add_edge(red_edges[i][0], red_edges[i][1], 0);

        for(int i = 0; i < bsize; i++)
            add_edge(blue_edges[i][0], blue_edges[i][1], 1);
    }

    void add_edge(int from, int to, int type)
    {
        edge[type][++tot[type]] = to;
        next[type][tot[type]] = head[type][from];
        head[type][from] = tot[type];
    }

private:
    int head[2][110] = {0};
    int edge[2][410] ;
    int next[2][410] = {0};
    int tot[2] = {0, 0};
    int node_num = 0;    
};