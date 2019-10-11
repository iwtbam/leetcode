#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.empty())
            return 0;
        
        auto cmp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        };

        sort(points.begin(), points.end(), cmp);

        vector<vector<int>> res = {};
        int size = points.size();
        res.push_back(points[0]);
        for(int i = 1; i < size; i++)
        {
            vector<int>& back = res.back();
            if(back[1] >= points[i][0])
            {
                back[0] = max(back[0], points[i][0]);
                back[1] = min(back[1], points[i][1]);
            }
            else
                res.push_back(points[i]);
        }

        return res.size();
    }
};