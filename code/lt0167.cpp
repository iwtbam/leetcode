#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0, p2 = numbers.size() - 1;
        while(p1 < p2 - 1)
        {
            int sum = numbers[p1] + numbers[p2];
            if(target == sum)
                return {p1+1, p2+1};
            else if(target > sum)
                p1++;
            else
                p2--;            
        }

        return {p1+1, p2+1};
    }

};