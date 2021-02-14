// https://leetcode-cn.com/problems/maximum-score-from-removing-substrings/
// maximum score from removing substrings
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        vector<char> s1, s2;
        size_t n = s.size();
        int ans = 0;
        
        string tokens[2] = {"ab", "ba"};
        
        if(y > x){
            swap(x, y);
            swap(tokens[0], tokens[1]);
        }
        
        s1.push_back(s[0]);
        
        
        for(int i = 1; i < n; i++){
            
            if(s1.size() && s[i] == tokens[0][1] && s1.back() == tokens[0][0]){
                ans += x;
                s1.pop_back();
            }else{
                s1.push_back(s[i]);
            }
        }
        
        
        if(s1.size() == 0)
            return ans;
        
        n = s1.size();
        s2.push_back(s1[0]);
        
        for(int i = 1; i < n ; i++){
            if(s2.size() > 0 && s1[i] == tokens[1][1] && s2.back() == tokens[1][0]){
                ans += y;
                s2.pop_back();
            }else{
                s2.push_back(s1[i]);
            }
        }
        
        return ans;
    }
};