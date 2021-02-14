// https://leetcode-cn.com/problems/valid-boomerang/
// valid boomerang
class Solution {
public:

#define EUD(p1, p2) (pow((pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)), 0.5))
    bool isBoomerang(vector<vector<int>>& points) {

        float s1 = EUD(points[0], points[1]);
        float s2 = EUD(points[1], points[2]);
        float s3 = EUD(points[0], points[2]);

        if(s1 < err || s2 < err || s3 < err)
            return false;

       // cout << s1  << " " << s2 << " "<< s3 << endl;
        return s1 + s2 > s3 && abs(s1 - s2) < s3;
    }

    const float err = 0.00001;
};