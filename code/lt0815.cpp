// https://leetcode-cn.com/problems/bus-routes/
// bus routes
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T)
            return 0;

        size_t size = routes.size();
        unordered_set<int> targets;
        int max_n = 0;
        int haveT = false, haveS = false;
        for(int i = 0; i < size; i++){
            size_t rs = routes[i].size();
            for(int j = 0; j < rs; j++){
                if(routes[i][j] == T){
                    haveT = true;
                    targets.insert(i);
                }
                if(routes[i][j] == S)
                    haveS = true;
                graph[routes[i][j]].insert(i);
            }
        }
        if(!haveT || !haveS)
            return -1;

        queue<int> q;
        vector<int> dis(size, -1);

        auto& sources = graph[S];
        size = sources.size();

        for(int source : sources){
            q.emplace(source);
            dis[source] = 1;
        }

        while(q.size())
        {
           int r = q.front();
           q.pop();

           if(targets.count(r) == 1)
                return dis[r];

           int rs = routes[r].size();
           for(int c  = 0; c < rs; c++)
           {
               auto& nexts = graph[routes[r][c]];

               for(int next : nexts){
                   if(dis[next] != -1 && dis[r] + 1 >= dis[next])
                        continue;
                    dis[next]= dis[r] + 1;
                    q.emplace(next);
               }
           }
        }

        return -1;

    }
private:
    unordered_map<int, unordered_set<int>> graph;
};