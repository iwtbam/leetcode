// https://leetcode-cn.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
// minimum time to collect all apples in a tree
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, int> parents = {};
        size_t size = edges.size();
        for(int i = 0; i < size; i++){
            parents[edges[i][1]] = edges[i][0];
        }
        
        unordered_set<int> nodes = {};

        for(int i = 0; i < n; i++){
            if(hasApple[i]){
                nodes.insert(i);
            }
        }
        
        
        int ans = 0;       
        vector<int> vis(n, 0);
        
        for(int node : nodes){
            while(vis[node] == 0 && node != 0){
                ans++;
                vis[node] = 1;
                node = parents[node];
            }
        }
        
        
        return ans * 2;
    }
};