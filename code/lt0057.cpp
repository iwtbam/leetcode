#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> vv;
        
        int size = intervals.size();
        int start = newInterval[0], end = newInterval[1];
        int insert = 0;
        for(int i = 0; i < size; i++)
        {
            if(newInterval[0] > intervals[i][1]){
                vv.push_back(intervals[i]);
                continue;
            }

            if(newInterval[1] < intervals[i][0]){
                
                if(insert == 0){
                    vv.push_back({start, end});
                    insert = 1;
                }
                vv.push_back(intervals[i]);
                continue;
            }
            
            
            if(newInterval[0] >= intervals[i][0] && newInterval[0] <=intervals[i][1]){
                start = intervals[i][0];   
            }
            
            if(newInterval[1] >= intervals[i][0] && newInterval[1] <=intervals[i][1]){
                end = intervals[i][1];
            }
            
            
        }
        
        if(insert == 0)
                vv.push_back({start, end});
        
        return vv;
    }
};