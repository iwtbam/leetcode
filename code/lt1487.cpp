// https://leetcode-cn.com/problems/making-file-names-unique/
// making file names unique
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> record;
        vector<string> res = {};
        size_t size = names.size();
        
        for(int i = 0;  i< size; i++){
            if(!record.count(names[i])){
                res.push_back(names[i]);
            }else{
                int index = record[names[i]];
                string key = names[i] + "(" + to_string(index) + ")";
                while(record.count(key)){
                    index = index + 1;
                    key = names[i] + "(" + to_string(index) + ")";
                }
                record[names[i]] = index;
                record[key]++;
                res.push_back(key);
            }
            
            record[names[i]]++;
        }
        
        return res;
    }
};