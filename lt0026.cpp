#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() < 2)
            return nums.size();
        
        auto iter1 = nums.begin();
        
        while(iter1 != nums.end())
        {
            auto iter2 = iter1 + 1;
            if(iter2 == nums.end())
                return nums.size();
            
            if(*iter1 == *iter2)
                nums.erase(iter2);
            else
                iter1++;
        }
        
        return nums.size();
    }
};