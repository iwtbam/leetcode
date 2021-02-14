// https://leetcode-cn.com/problems/number-of-boomerangs/
// number of boomerangs
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int size = points.size();
        int ans = 0;
        for(int i = 0; i < size; i++){
            unordered_map<int, int> record;
            for(int j = 0; j < size; j++) {
                if(i == j)
                    continue;
                record[dis(points, i, j)]++;
            }

            for(auto [x, y] : record) {
                ans += y * (y - 1);
            }
        }
        return ans;
    }

    int dis(vector<vector<int>>& points, int i, int j) {
        return pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
    }
};