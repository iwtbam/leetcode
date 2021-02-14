// https://leetcode-cn.com/problems/can-convert-string-in-k-moves/
// can convert string in k moves
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size())
            return false;
        
        size_t size = s.size();
        
        vector<int> record(26, 0);
        
        for(int i = 0; i < size; i++){
            if(s[i] == t[i])
                continue;
            
            
            int diff = t[i] - s[i];
            
            if(diff < 0){
                diff += 26;
            }
            
            int mod = diff % 26;
            
            if(mod + record[mod] * 26 > k)
                return false;
            
            record[mod]++;

        }
        
        return true;
    }
};