// https://leetcode-cn.com/problems/check-if-a-string-can-break-another-string/
// check if a string can break another string
class Solution {
public:
    bool less(const string& s1, const string& s2){
        size_t size = s1.size();
        for(int i = 0; i < size; i++){
            if(s1[i] > s2[i])
                return false;
        }
        
        return true;
    }
    
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return less(s1, s2) || less(s2, s1);
    }
};