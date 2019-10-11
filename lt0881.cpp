#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if(people.empty())
            return 0;

        sort(people.begin(), people.end());
        int size = people.size();
        int i = 0, j = size - 1, ans = 0;

        while(i <= j)
        {
            ans++;
            if(people[i] + people[j] <= limit)
                i++;
            j--;
        }

        return ans;
    }
};