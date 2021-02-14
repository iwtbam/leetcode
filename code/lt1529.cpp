// https://leetcode-cn.com/problems/bulb-switcher-iv/
// bulb switcher iv
class Solution {
public:
    int minFlips(string target) {
        size_t size = target.size();
        int flip = 0;
        int ans = 0;
        for(int i = 0; i < size; i++){
            int state = target[i] - '0' + flip;
            if(state % 2 == 0)
                continue;
            ans++;
            flip = (flip + 1) % 2;
        }
        
        return ans;
    }
};