// https://leetcode-cn.com/problems/find-eventual-safe-states/
// find eventual safe states
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        size_t N = graph.size();
        vector<vector<int>> reG = {N, vector<int>()};
        vector<int> degrees(N, 0);
        vector<int> res;
        queue<int> cans;
        for(int i = 0; i < N; i++){
            degrees[i] = graph[i].size();
            for(int j = 0; j < degrees[i]; j++){
                reG[graph[i][j]].push_back(i);
            }
            if(degrees[i] == 0){
                res.push_back(i);
                cans.push(i);
            }
        }

        while(cans.size()){
            int size = cans.size();
            for(int i = 0; i < size; i++){
                auto& froms = reG[cans.front()];
                cans.pop();
                for(int from : froms){
                   degrees[from]--;
                   if(degrees[from] == 0){
                       cans.push(from);
                       res.push_back(from);
                   } 
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};