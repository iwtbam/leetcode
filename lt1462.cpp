// https://leetcode-cn.com/problems/course-schedule-iv/
// course schedule iv
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph = {static_cast<size_t>(n), vector<int>()};
        vector<vector<bool>> pres = {static_cast<size_t>(n), vector<bool>(n, false)};
        vector<int> indegrees(n, 0);
        vector<int> visited(n, 0);
        size_t size = prerequisites.size();
        for(int i = 0; i < size; i++){
            vector<int>& r = prerequisites[i];
            graph[r[0]].push_back(r[1]);
            indegrees[r[1]]++;
        }

        vector<int> cans;
        for(int i = 0; i < n; i++){
            if(indegrees[i] == 0) {
                cans.push_back(i);
                visited[i] = 1;
            }
        }


        while(cans.size()){
            int csize = cans.size();
            for(int i = 0; i < csize; i++){
                auto& children = graph[cans[i]];  
                int num  = children.size();
                for(int j = 0; j < num; j++){
                    indegrees[children[j]]--;
                }
                
                mark(graph, pres, cans[i], cans[i]);
            }
            cans.clear();
            for(int i = 0; i < n; i++){
                if(indegrees[i] == 0 && visited[i] == 0) {
                    cans.push_back(i);
                    visited[i] = 1;
                }
            }
        }


        vector<bool> res;

        for(auto& query : queries){
            res.push_back(pres[query[0]][query[1]]);
        }

        return res;

    }

    void mark(vector<vector<int>>& graph, vector<vector<bool>>& pres, int cur, int node){
        auto& children = graph[node];
        size_t size = children.size();
        for(int i = 0; i < size; i++){
            if(pres[cur][children[i]])
                continue;
            pres[cur][children[i]] = true;
            mark(graph, pres, cur, children[i]);
        }
    }
};