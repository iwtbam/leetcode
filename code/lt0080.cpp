#include <vector>
#include <algorithm>
using namespace std;


class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        //sort(nums.begin(), nums.end());  数据默认有序
        for(int i = nums.size() - 1; i > 1; i--)
        {
            if(nums[i] == nums[i - 2])
                nums.erase(nums.begin() + i);
        }

        return nums.size();
    }
};