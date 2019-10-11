#include <vector>

using namespace std;

class NumArray {
public:

    vector<int> nums = {};
    NumArray(vector<int>& nums) {

        int size = nums.size();
        this->nums= nums;
        for(int i = 1;i < size; i++)
            this->nums[i] += this->nums[i-1];
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return nums[j];
        return nums[j] - nums[i-1];
    }
};