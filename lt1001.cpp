// https://leetcode-cn.com/problems/grid-illumination/
// grid illumination
class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> rows = {};
        unordered_map<int, int> cols = {};
        unordered_map<int, int> dia1 = {};
        unordered_map<int, int> dia2 = {};
        unordered_set<long long> lamp_pos = {}; 
        vector<int> res = {};
        for(const vector<int>& lamp : lamps){
            rows[lamp[0]]++;
            cols[lamp[1]]++;
            dia1[lamp[0] - lamp[1]]++;
            dia2[lamp[0] + lamp[1]]++;
            lamp_pos.insert((long long)lamp[0] * N + lamp[1]);
        }
        
        
        std::function<void(int, int)> query_func = [&](int x, int y){
            
            
             if(rows.count(x) || cols.count(y) || dia1.count(x - y) || dia2.count(x + y))
                 res.push_back(1);
             else
                 res.push_back(0);
            
            for(int i = 0; i < 9; i++){
                int nx = x + dxs[i];
                int ny = y + dys[i];
                long long npos = (long long)nx * N + ny;
                if(nx >= 0 && nx < N && ny >= 0 && ny < N && lamp_pos.count(npos)){

                    lamp_pos.erase(npos);
                    rows[nx]--;
                    if(rows[nx] <= 0)
                        rows.erase(nx);
                    
                    cols[ny]--;

                    if(cols[ny] <= 0)
                        cols.erase(ny);
                    
                    dia1[nx - ny]--;
                    if(dia1[nx - ny] <=0)
                        dia1.erase(nx - ny);
                    
                    dia2[nx + ny]--;
                    if(dia2[nx + ny] <= 0)
                        dia2.erase(nx + ny);
                    
                }
            }
        };
        
        for(const vector<int>& query : queries){
            query_func(query[0], query[1]);
        }
        
        return res;
    }
    
    int dxs[9] = {0, 0,  0, 1, 1,  1, -1, -1, -1};
    int dys[9] = {0, 1, -1, 0, 1, -1,  0,  1, -1};
};