#include <vector>

using namespace std;

class Solution{
public:
    bool search(vector<int>& nums, int target){
        return search_rotate_index(nums);
    }

    int search_rotate_index(vector<int>& nums)
    {
        int l = 0, h = nums.size() - 1;
        while(l < h)
        {
            int m = (l + h)/2;
            if(nums[m] >= nums[l])
                l = m + 1;
            else
                h = m - 1;
        }

        return l;
    }
};


int main()
{
    using IterType  = vector<int>::reference;
  
}