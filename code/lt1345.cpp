// https://leetcode-cn.com/problems/jump-game-iv/
// jump game iv
class Solution {
public:
    int minJumps(vector<int>& arr) {
        size_t size = arr.size();
        vector<int> dis(size, -1);

        unordered_map<int, vector<int>> record;
        unordered_set<int> vis2;

        for(int i = 0; i < size; i++)
            record[arr[i]].push_back(i);
       
        queue<int> q;
        q.emplace(0);
        dis[0] = 0;

        while(q.size())
        {
            int c = q.front();
            q.pop();
            size_t qs = q.size();

            for(int i = 0; i < 2; i++)
            {
                int n = c + dirs[i];
                if(n < 0 || n >= size)
                    continue;
                if(dis[n] != -1 && dis[c] + 1 >= dis[n])
                    continue;
                dis[n] = dis[c] + 1;
                q.emplace(n);
            }
            
            if(vis2.count(arr[c]) == 1)
                continue;

            vis2.insert(arr[c]);

            vector<int>& relation = record[arr[c]];
            int rs = relation.size(); 
            for(int j = rs - 1; j >= 0; j--)
            {
                int n = relation[j];
                if(dis[n] != -1 && dis[c] + 1 >= dis[n])
                    continue;
                dis[n] = dis[c] + 1;
                q.emplace(n);
            }          
        }

        return dis[size - 1];
    }
private:
    int dirs[2] = {1, -1};
};