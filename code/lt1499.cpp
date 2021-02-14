// https://leetcode-cn.com/problems/max-value-of-equation/
// max value of equation
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> q;
        size_t size = points.size();
        int res = INT_MIN;
        for(int i = 0; i < size; i++){
            int x = points[i][0];
            int y = points[i][1];
            
            while(q.size() && x - q.front().first > k){
                  q.pop_front();
            }
            
            if(q.size())
                res = max(res, x + y + q.front().second);
            
            int sum = y - x;
            while(q.size() && sum > q.back().second){
                q.pop_back();
            }
            
            q.push_back({x, sum});
            
           
        }
        return res;
    }
};