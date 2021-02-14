// https://leetcode-cn.com/problems/open-the-lock/
// open the lock
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        size_t deadends_size = deadends.size();
        for(int i = 0; i < deadends_size; i++)
            blocked.insert(deadends[i]);
        queue<string> q;
        q.emplace("0000");
        dis["0000"] = 0;

        while(q.size())
        {
            string c = q.front();
            q.pop();
            if(blocked.count(c))
                continue;
            string n = c;

            for(int i = 0; i < 4; i++)
            {
                for(int d = -1; d <= 1; d += 2)
                {
                    n[i] = (c[i] - '0' + d + 10) % 10 + '0';
                    if(dis.count(n) && dis[c] + 1 >= dis[n])
                        continue;
                    dis[n] = dis[c] + 1;
                    q.emplace(n);
                }
                n[i] = c[i];

            }

        }

        return dis.count(target) ? dis[target] : -1;
    }

private:
    int dirs[2] = {-1, 1};
    unordered_map<string, int> dis;
    unordered_set<string> blocked;
};