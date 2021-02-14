#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& v1, const vector<int>& v2)->bool{
            return v1[0] < v2[0];
        };

        sort(intervals.begin(), intervals.end(), cmp);

        int pre = 0;
        int size = intervals.size();
        int count = 0;
        for(int i = 1; i < size; i++){
            if(intervals[i][0] < intervals[pre][1]){
                if(intervals[pre][1] > intervals[i][1])
                    pre = i;
                count++;
            }
            else
                pre = i;
        }
        return count;
    }
};