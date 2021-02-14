// https://leetcode-cn.com/problems/minimum-deletions-to-make-character-frequencies-unique/
// minimum deletions to make character frequencies unique
class Solution {
public:
    int minDeletions(string s) {
        int record[26] = {0};
        int size = s.size();
        for(int i = 0; i < size; i++)
            record[s[i] - 'a']++;
        
        vector<int> vis(size + 1, 0);
        sort(record, record + 26);
        
        int ans = 0;
        
        for(int i = 25; i>= 0; i--){
            if(record[i] == 0)
                break;
            vis[0] = 0;
            for(int j = 0; j <= record[i]; j++){
                if(vis[record[i] - j] == 0){
                    vis[record[i] - j] = 1;
                    ans += j;
                    break;
                }   
            }
        }
        
        return ans;
    }
};