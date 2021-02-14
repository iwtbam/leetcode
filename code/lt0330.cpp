#include <vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n){
        int pathces = 0;
        long miss = 1;
        int size = nums.size(), i = 0;
        while(miss <= n){
            if(i < size && nums[i] <= miss){
                miss += nums[i++];
            }else{
                miss+=miss;
                pathces++;
            }
        }

        return pathces;
    }
};