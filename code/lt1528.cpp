// https://leetcode-cn.com/problems/shuffle-string/
// shuffle string
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res = s;
        size_t size = s.size();
        for(int i = 0; i < size; i++){
            res[indices[i]] = s[i];
        }
        
        return res;
    }
};