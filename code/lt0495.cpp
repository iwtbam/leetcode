#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        size_t size = timeSeries.size();
        if(size == 0)
            return 0;
        int over_time = timeSeries[0] + duration;
        int count = duration;
        for(int i = 1; i < size; i++)
        {
            
            if(over_time <= timeSeries[i]){
                over_time = timeSeries[i] + duration;
            }
            else{
                count -= (over_time - timeSeries[i]);
                over_time = max(over_time, timeSeries[i] + duration);
            }

            count+= duration;
            
        }

        return count;
    }
};