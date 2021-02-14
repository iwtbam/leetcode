// https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
// change minimum characters to satisfy one of three conditions
class Solution {
public:
    int minCharacters(string a, string b) {
        
        int r1[26] = {0},s1[27] = {0}, r2[26] = {0}, s2[27] = {0}, r3[26] = {0};
        int la = a.size(), lb = b.size();
        for(int i = 0; i < la; i++)
            r1[a[i] - 'a']++;
        for(int i = 0; i < 26; i++)
            s1[i + 1] = s1[i] + r1[i];
        for(int i = 0; i < lb; i++)
            r2[b[i] - 'a']++;
        for(int i = 0; i < 26; i++)
            s2[i + 1] = s2[i] + r2[i];
        int cost = 100000000;
        for(int i = 0; i < 25; i++){
            cost = min(cost, s1[26] - s1[i + 1] + s2[i + 1]);
            cost = min(cost, s2[26] - s2[i + 1] + s1[i + 1]);
        }
        
        int num = 0;
        for(int i = 0; i < 26; i++){
            r3[i] = r1[i] + r2[i];
            num = max(num, r3[i]);
        }
        
        return min(cost, la + lb - num);
    }

    
};