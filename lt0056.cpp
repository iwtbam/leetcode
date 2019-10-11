#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        int size = intervals.size();

        if(size == 0)
            return {};
        sort(intervals.begin(), intervals.end(), [](vector<int>& ele1, vector<int>& ele2)->bool{
            return ele1[0] < ele2[0];
        });
        
        vector<vector<int>> res = {};

        res.push_back(intervals[0]);

        for(int i = 1; i < size; i++){
            auto& back = res.back();
            if(back[1] >= intervals[i][0])
                back[1] = max(back[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
            
        }

        return res;
    }
};