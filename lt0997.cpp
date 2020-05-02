class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> count(N + 1, 0);
        vector<int> visited(N + 1, 0);
        vector<int> can = {};
        
        for(const vector<int>& item : trust){
            visited[item[0]] = 1;
            count[item[1]]++;
        }
        
        for(int i = 1; i <= N; i++){
            if(count[i] == N - 1 && !visited[i]){
                return i;
            }
        }
        
        return -1;
        
    }
};