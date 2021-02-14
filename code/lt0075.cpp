#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums){
        int record[3] = {0, 0, 0};
        int size = nums.size();
        for(int i = 0; i < size; i++)
            record[nums[i]]++;
        int index = 0;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < record[i]; j++)
                nums[index++] = i;
        }
    }
};