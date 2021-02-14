#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> nHeights = heights;
        sort(nHeights.begin(), nHeights.end());
        int num = 0;
        for(int i = 0; i < heights.size(); i++)
            if(heights[i]!=nHeights[i])
                num++;
        return num;
    }
};