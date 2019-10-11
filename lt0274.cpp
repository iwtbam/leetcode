#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0;
        int size = citations.size();
        for(int i = 0; i < size; i++)
        {
            h = max(h,min(citations[i], size - i));
        }
        
        return h;
    }
};