// https://leetcode-cn.com/problems/jump-game-vi/
// jump game vi
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        int ans = nums[0];
        int n = nums.size();
        q.emplace_back(ans, 0);
        for(int i = 1; i < n; i++){
            while(q.size() && i - q.front().second > k)
                q.pop_front();
            ans = q.front().first + nums[i];
            while(q.size() && ans > q.back().first)
                q.pop_back();
            q.emplace_back(ans, i);
        }

        return ans;

    }
};