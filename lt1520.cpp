// https://leetcode-cn.com/problems/maximum-number-of-non-overlapping-substrings/
// maximum number of non overlapping substrings
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        size_t size = s.size();
        vector<pair<int, int>> record(26, {-1, -1});
        for(int i = 0; i < size; i++){
            if(record[s[i] - 'a'].first == -1){
                record[s[i] - 'a'].first = i;
            }
            record[s[i] - 'a'].second = i;
        }
        
        
        for(int i = 0; i < 26; i++){
            if(record[i].first == -1)
                continue;
            
          
            while(true) {
                int first = record[i].first;
                int second = record[i].second;
                for(int j = record[i].first; j <= record[i].second; j++){
                    int index = s[j] - 'a';
                    first = min(first, record[index].first);
                    second = max(second, record[index].second);
                }
                if(record[i].first == first && record[i].second == second)
                    break;
                record[i].first = first;
                record[i].second = second;
            }
        }
       
        
        
        vector<pair<int, int>> record2;
        

        
     
        
        for(int i = 0; i < 26; i++){
            if(record[i].first != -1){
                record2.push_back(record[i]);
            }
        }
        
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second < p2.second;
        };
        
        sort(record2.begin(), record2.end(), cmp);
        
         
        size = record2.size();
        
        vector<string> res;
        int left = -1;
        
        
        for(int i = 0; i < size; i++){
            if(record2[i].first <= left)
                continue;
            
            left = record2[i].second;
            
            int len = record2[i].second - record2[i].first + 1;
            
            res.push_back(s.substr(record2[i].first, len));
        }
        return res;
    }
};