// https://leetcode-cn.com/problems/destination-city/
// destination city
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> froms;
        vector<string> tos;
        size_t size = paths.size();
        for(int i = 0; i < size; i++){
            froms.insert(paths[i][0]);
            tos.push_back(paths[i][1]);
        }
        
        size = tos.size();
        
        for(int i = 0; i < size; i++){
            if(froms.count(tos[i]) == 0)
                return tos[i];
        }
        
        return "-1";
    }
};