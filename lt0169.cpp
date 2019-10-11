#include <vector>
#include <iostream>

using namespace std;


class Solution{
public:
    int majorityElement(vector<int>& nums){
        int target = nums[0];
        int len = 1;
        for(int i = 1; i < nums.size(); i++){
            
            if(len == 0)
            {
                target = nums[i];
                continue;
            }

            if(nums[i]!=target)
                len--;
            else
                len++;
        }

        cout << target << endl;
    }
};