// https://leetcode-cn.com/problems/escape-the-ghosts/
// escape the ghosts
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis = abs(target[0]) + abs(target[1]);
        for(auto& ghost : ghosts) {
            if(abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= dis){
                return false;
            }
        }
        return true;
    }
};