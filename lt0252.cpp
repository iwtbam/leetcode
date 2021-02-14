// https://leetcode-cn.com/problems/meeting-rooms/
// meeting rooms
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        map<int, int> record;

        size_t size = intervals.size();

        for(int i = 0; i < size; i++){
            record[intervals[i][0]]++;
            record[intervals[i][1]]--;
        }

        int sum = 0;

        for(auto [key, v] : record){
            sum += v;
            if(sum > 1)
                return false;
        }

        return true;
    }
};