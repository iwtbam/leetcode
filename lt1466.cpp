// https://leetcode-cn.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
// reorder routes to make all paths lead to the city zero
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res = 0;
        vector<vector<int>> tos(n);
        vector<vector<int>> froms(n);
        
        for(int i = 0; i < n - 1; i++){
            int from = connections[i][0];
            int to = connections[i][1];
            froms[to].push_back(from);
            tos[from].push_back(to);
        }
        
        queue<int> q;
        vector<int> vis(n, 0);
        vis[0] = 1;
        q.push(0);
        while(q.size()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                int front = q.front();
                
                vector<int> to = tos[front];
                
                int to_size = to.size();
                
                for(int j = 0; j < to_size; j++){
                    if(vis[to[j]] == 1)
                        continue;
                    res += 1;
                    vis[to[j]] = 1;
                    q.push(to[j]);
                }
               
                vector<int> from = froms[front];
                
                int from_size = from.size();
                for(int j = 0; j < from_size; j++){
                    if(vis[from[j]] == 1)
                        continue;
                   
                    vis[from[j]] = 1;
                    q.push(from[j]);
                }
                
                
                q.pop();
               
            }
         
        }
        
        return res;
    }
};