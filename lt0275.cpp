#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int lo = 0, hi = citations.size() - 1;
        int h_index = 0;
        while(lo < hi)
        {
            int mid = (lo + hi) / 2;
            if(size - mid == citations[mid])
                return citations[mid];
            
            if(size - mid > citations[mid])
                lo = mid + 1;
            else
                hi = mid;
            
        }

        return citations[lo];
    }
};