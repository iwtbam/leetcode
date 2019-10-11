#include <vector>

using namespace std;

class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int l = 0, h = A.size();
        while(l < h)
        {
            int m = (l + h) >> 1;
            if(A[m] == l)
                return m;
            else if(A[m] > m)
                h = m - 1;
            else
                l = m + 1;
        }

        if(A[l] == l)
            return l;
        return -1;
    }
};