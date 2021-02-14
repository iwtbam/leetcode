// https://leetcode-cn.com/problems/number-of-good-ways-to-split-a-string/
// number of good ways to split a string
class Solution {
public:
    int numSplits(string s) {
        size_t len = s.size();
        unordered_set<char> record = {};
        vector<int> left(len, 0);
        for(int i = 0; i < len; i++){
            record.insert(s[i]);
            left[i] = record.size();
        }
        
        record.clear();
        int num = 0;
        for(int i = len - 1; i >= 0; i--){
            if(record.size() == left[i]){
                num++;
            }
            
            record.insert(s[i]);
        }
        
        return num;
    }
};