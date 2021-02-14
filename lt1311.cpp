// https://leetcode-cn.com/problems/get-watched-videos-by-your-friends/
// get watched videos by your friends
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        size_t n = friends.size();
        vector<vector<int>> graph ={n, vector<int>()};
        vector<int> visited(n, 0);
        
        for(int i = 0; i < n; i++){
            vector<int> f = friends[i];
            for(int node: f){
                graph[i].push_back(node);
                graph[node].push_back(i);
            }
        }
        
        queue<int> q = {};
        q.push(id);
        visited[id] = 1;
        int cur_level = 0;
        vector<int> peope = {};
        
        while(q.size() && cur_level < level){
            peope = {};
            int size = q.size();
            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();
                vector<int>& nexts = graph[cur];
                for(int next : nexts){
                    if(visited[next])
                        continue;
                    visited[next] = 1;
                    q.push(next);
                    peope.push_back(next);
                }
            }
            cur_level++;
        }
        
        if(cur_level < level)
            return {};
        
        unordered_map<string, int> record = {};
        for(int fid : peope){
            vector<string>& videos = watchedVideos[fid];
            for(string video : videos)
                record[video]++;
        }
        
        vector<pair<string, int>> unordered_res = {record.begin(), record.end()};
        sort(unordered_res.begin(), unordered_res.end(), [&](pair<string, int>& p1, pair<string, int>& p2){
           return p1.second == p2.second ? p1.first  < p2.first : p1.second < p2.second; 
        });
        
        vector<string> res = {};
        
        for(pair<string, int>& video : unordered_res)
            res.push_back(video.first);
        
        
        return res;
        
    }
};