// https://leetcode-cn.com/problems/consecutive-characters/
// consecutive characters
class Solution {
public:
    int maxPower(string s) {
        size_t size = s.size();
        int l = 0, ml = 0;
        for(int i = 0; i < size - 1; i++){
            if(s[i] == s[i + 1]){
                l++;
            }else{
                l = 0;
            }
            
            ml = max(ml, l);
        }
        
        return ml + 1;
    }
};