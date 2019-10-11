#include <vector>

using namespace std;

class Solution {
public:
    using ivec = vector<int>;
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        ivec p1p2 = {p1[0] - p2[0], p1[1] - p2[1]};
        ivec p1p3 = {p1[0] - p3[0], p1[1] - p3[1]};
        ivec p1p4 = {p1[0] - p4[0], p1[1] - p4[1]};
        ivec p2p4 = {p2[0] - p4[0], p2[1] - p4[1]};
        ivec p3p4 = {p3[0] - p4[0], p3[1] - p4[1]};
        ivec p2p3 = {p2[0] - p3[0], p2[1] - p3[1]};

        if(dot(p1p2, p1p3) == 0)
            return dot(p1p2, p2p4) == 0 && dot(p1p3, p3p4) == 0 && dis2(p1p2) && dis2(p1p2) == dis2(p1p3);
        if(dot(p1p2, p1p4) == 0)
            return dot(p1p2, p2p3) == 0 && dot(p1p4, p3p4) == 0 && dis2(p1p2) && dis2(p1p2) == dis2(p1p4);
        if(dot(p1p3, p1p4) == 0)
            return dot(p1p3, p2p3) == 0 && dot(p1p4, p2p4) == 0 && dis2(p1p3) && dis2(p1p3) == dis2(p1p4);
        
        return false;
    }

    inline int dot(ivec p1, ivec p2)
    {
        return p1[0] * p2[0] + p1[1] * p2[1];
    }
    
    int dis2(ivec p1)
    {
        return p1[0] * p1[0] + p1[1] * p1[1];
    }
};