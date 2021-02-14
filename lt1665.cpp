// https://leetcode-cn.com/problems/minimum-initial-energy-to-finish-tasks/
// minimum initial energy to finish tasks


class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        size_t size = tasks.size();
        
        auto cmp = [](const vector<int>& v1, const vector<int>& v2)
        {
            int v1_cost = max(v1[1], v1[0] + v2[1]);
            int v2_cost = max(v2[1], v2[0] + v1[1]);
            return v1_cost < v2_cost;
        };
        
        sort(tasks.begin(), tasks.end(), cmp);
        long long res = 0;
        for(int i = 0; i < size; i++)
            res += tasks[i][0];
        
        
        long long cnt = 0, ans = res;
        for(int i = 0; i < size; i++){
            if(ans < tasks[i][1]){
                cnt += tasks[i][1] - ans;
                ans = tasks[i][1];
            }
            ans -= tasks[i][0];
        }
        return res + cnt;
    }  
};