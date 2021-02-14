#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum1 = ((size + 1) * size) / 2;
        int sum2 = accumulate(nums.begin(), nums.end(), 0);
        return sum1 - sum2; 
    }
};