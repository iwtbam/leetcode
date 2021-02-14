#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sp= nums[0];
        int fp = nums[0];
        do
        {
            sp = nums[sp];
            fp = nums[nums[fp]];
        } while (sp != fp);

        int p1 = nums[0];
        int p2 = sp;
        while(p1!=p2)
        {
            p1 = nums[p1];
            p2 = nums[p2];
        }

        return p1;
    }
};