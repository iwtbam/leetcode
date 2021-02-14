// https://leetcode-cn.com/problems/avoid-flood-in-the-city/
// avoid flood in the city
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
     //   unordered_set<int> record = {};
        unordered_map<int, int> pres =  {};
        size_t size = rains.size();
        vector<int> res(size, -1);
        list<int> zeros;        
        for(int i = 0; i < size; i++){
            if(rains[i] == 0){
                zeros.push_back(i);
                res[i] = 1;
                continue;
            }
            
            if(pres.count(rains[i])){
                bool solve = false;
                int d = zeros.size();
                for(auto iter = zeros.begin(); iter != zeros.end(); iter++){
                  
                    int pos = *iter;
                    if(pos > pres[rains[i]]){
                        res[pos] = rains[i];
                        zeros.erase(iter);
                        solve = true;
                        break;
                    }
                }
                if(!solve)
                    return {};
            }
            pres[rains[i]] = i; 
        }
        
        
     
        return res;
    }
};