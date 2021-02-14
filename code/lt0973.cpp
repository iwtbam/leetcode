#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    
    struct cmp
    {
        bool operator()(const pair<int, double>& p1, const pair<int, int>& p2)
        {
            return p1.second < p2.second;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, double>, vector<pair<int, double>>, cmp> q;
        int size = points.size();
        
        for(int i = 0; i < size; i++)
        {
            pair<int, double> temp = {i, dis(points[i])};
            q.push(temp);
            if(i >= K)
                q.pop();
        }
        
        vector<vector<int>> res = {};
        
        while(!q.empty())
        {
            res.push_back(points[q.top().first]);
            q.pop();
        }
        
        return res;
    }
    
    inline double dis(vector<int>& point)
    {
        return point[0] * point[0] + point[1] * point[1];
    }
};