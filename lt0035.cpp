#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto iter = lower_bound(nums.begin(), nums.end(), target);
        return iter - nums.begin();
    }
};