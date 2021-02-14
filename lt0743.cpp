// https://leetcode-cn.com/problems/network-delay-time/
// network delay time
struct Edge
{
    int vertice;
    int weight;
    int next;
    Edge(int w = 0, int v = 0, int n = 0):weight(w), vertice(v), next(n){}
};


class Solution {
public: 

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        size_t edge_size = times.size();
        size_t node_size = N;

        edges.resize(edge_size + 1);
        head.resize(node_size + 1);

        for(int i = 0; i < edge_size; i++)
            add_edge(times[i][0], times[i][1], times[i][2]);

        vector<int> dis(node_size + 1, INF);
        vector<bool> vis(node_size + 1, false);
        dis[K] = 0;
      

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.emplace(0, K);

        while(q.size())
        {
            auto [cost, from] = q.top();
            vis[from] = true;
            q.pop();
            for(int i = head[from]; i; i = edges[i].next)
            {
                auto [to, w, n] = edges[i];
                if(!vis[to] && cost + w < dis[to])
                {
                    dis[to] = dis[from] + w;
                    q.emplace(dis[to], to);
                }
            }
        }
        int max_dis = *max_element(dis.begin() + 1, dis.end());
        return max_dis == INF ? -1 : max_dis;
    }

    void add_edge(int from, int to, int w)
    {
        edges[++tot].vertice = to;
        edges[tot].weight = w;
        edges[tot].next = head[from];
        head[from] = tot;
    }

private:
    
    vector<Edge> edges;
    vector<int> head;
    int tot = 0;
    const int INF = 0x3f3f3f3f;
};