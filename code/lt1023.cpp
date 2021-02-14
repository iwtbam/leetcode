// https://leetcode-cn.com/problems/camelcase-matching/
// camelcase matching
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res = {};
        int size = queries.size();
        
        cout << (int)('a') << endl;
        
        for(int i = 0; i < size; i++)
            res.push_back(match(queries[i], pattern));
        
        return res;
    }
    
    bool match(const string& query, const string& pattern){
        int pq = 0, pp = 0;
        int qs = query.size();
        int ps = pattern.size();
        
        while(pq < qs && pp < ps){
            
            //cout << query[pq] << " " << pattern[pp] << endl;
            
            if(query[pq] == pattern[pp]){
                pq++;
                pp++;
            }else{
                if(query[pq] < 'a')
                    return false;
                pq++;
            }
            
          
        }
        
        if(pp < ps && pq >= qs)
            return false;
        
        while(pq < qs){
            if(query[pq] < 'a')
                return false;
            pq++;
        }
        
        return true;
    }
    
};