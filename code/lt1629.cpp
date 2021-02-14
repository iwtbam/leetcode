// https://leetcode-cn.com/problems/slowest-key/
// slowest key
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int times[26] = {0};
        int n = releaseTimes.size();
        int pre = 0;
        for(int i = 0; i < n; i++){
            int pos = keysPressed[i] - 'a';
            times[pos] = max(times[pos], releaseTimes[i] - pre);
            pre = releaseTimes[i];
        }
        
        int pos = 0;
        for(int i = 0; i < 26; i++){
            if(times[i] >= times[pos])
                pos = i;
        }
        
        return 'a' + pos;
    }
};