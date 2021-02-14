// https://leetcode-cn.com/problems/minimum-jumps-to-reach-home/
// minimum jumps to reach home
class Solution {
public:


    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

        size_t size = forbidden.size();
        memset(dis, 0x3f, sizeof(dis));

        for(int i = 0; i < size; i++)
        {
            if(forbidden[i] < x + 4001)
            {
                dis[forbidden[i]][0] = -1;
                dis[forbidden[i]][1] = -1;
            }
        }

        queue<pair<int, int>> q;
        q.emplace(0, 0);


        dis[0][0] = 0;

        while(q.size()){
            auto [s, c] = q.front();
            q.pop();

            if(c + a <= x + 6000 && dis[c][s] + 1 < dis[c + a][0])
            {
                dis[c + a][0]  = dis[c][s] + 1;
                q.emplace(0, c + a);
            }

            if(s == 1 || c - b <= 0 || dis[c][s] + 1 > dis[c - b][1])
                continue;
            
            dis[c - b][1] = dis[c][s] + 1;
            q.emplace(1, c - b);

        }

        int res = min(dis[x][0], dis[x][1]);
        return res == INF ? -1 : res;
    }

private:
    int dis[10000][2];
    const int INF = 0x3f3f3f3f;
};