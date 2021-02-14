#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution{
public:
    int maxProduct(vector<int>& nums){
        int m = INT_MAX, imax = 1, imin = 1;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums[i] < 0){
                imax = imax ^ imin;
                imin = imax ^ imin;
                imax = imax ^ imin;
            }

            imax = max(imax*nums[i], nums[i]);
            imin = min(imin*nums[i], nums[i]);
            m = max(m, imax);
        }

        return m;
    }
};