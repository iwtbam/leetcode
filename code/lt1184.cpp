// https://leetcode-cn.com/problems/distance-between-bus-stops/
// distance between bus stops
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int total = accumulate(distance.begin(), distance.end(), 0);
        int s = min(start, destination);
        int e = max(start, destination);
        int dis = accumulate(distance.begin() + s, distance.begin() + e, 0);
        // cout << dis << endl;
        return dis * 2 < total ? dis : total - dis;
    }
};