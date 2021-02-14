#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class Solution{
public:
    int minMeetingRooms(vector<vector<int>> intervals){

        sort(intervals.begin(), intervals.end(), [](vector<int>& e1, vector<int>& e2) -> bool{
            return e1[0] == e2[0] ? e1[1] > e2[1] : e1[0] < e2[0];
        });

        int rooms = 0;
        int size = intervals.size();
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < size - 1; i++){
            q.push(intervals[i][1]);
            if(intervals[i][0] < q.top())
                rooms++;
            else
                q.pop();
        }

        return rooms;
    }
};


