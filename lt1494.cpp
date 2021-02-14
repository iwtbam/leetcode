// https://leetcode-cn.com/problems/parallel-courses-ii/
// parallel courses ii
struct Cmp {
    bool operator()(const pair<int, int>& p1, pair<int, int>& p2){
        return p1.second < p2.second;
    }  
};

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> indegrees(n + 1, 0);
        vector<int> visited(n + 1, 0);
        vector<vector<int>> graph(n + 1, vector<int>());
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> cans;
        
        int res = 0;
        
        size_t size = dependencies.size();
        
        for(int i = 0; i < size; i++){
            vector<int>& d = dependencies[i];
            indegrees[d[1]]++;
            graph[d[0]].push_back(d[1]);
          //  cout << d[0] << " "<< d[1] << "/";
        }
        
          
        
        for(int i = 1; i <= n; i++){
            if(indegrees[i] == 0){
                cans.push({i, graph[i].size()});
                visited[i] = 1;
            }
            
         
        }
        
        while(cans.size()){
            res += 1;
            int csize = min(static_cast<size_t>(k), cans.size());
            for(int i = 0; i < csize; i++){
                auto index = cans.top();
                cans.pop();
                vector<int>& childrens = graph[index.first];
                for(int j = 0; j < childrens.size(); j++){
                    indegrees[childrens[j]]--;
                }
            }
            
            
            for(int i = 1; i <=n; i++){
                if(indegrees[i] == 0 && visited[i] == 0){
                    cans.push({i, graph[i].size()});
                    visited[i] = 1;
                }
            }
        }
        
        return res;
    }
};