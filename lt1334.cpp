// https://leetcode-cn.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// find the city with the smallest number of neighbors at a threshold distance
class Solution {

private:
    const int INF = 0x3f3f3f3f;

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis = {n, vector<int>(n, INF)};
        size_t edge_num = edges.size();
        for(size_t i = 0; i < edge_num; i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            dis[node1][node2] = edges[i][2];
            dis[node2][node1] = edges[i][2];
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                if(dis[i][k] == INF)
                    continue;
                for(int j = 0; j < n; j++){
                    
                    if(dis[k][j] == INF || i == j)
                        continue;
                    if(dis[i][k] + dis[k][j] < dis[i][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        
        int res = -1;
        int count = INF;
        
        for(int i = 0; i < n; i++){
            int cur = 0;
            for(int j = 0; j < n; j++){
                if(dis[i][j] <= distanceThreshold)
                    cur++;
            }
            if(cur <= count){
                count = cur;
                res = i;
            }
        }
        
        return res;
    }

};