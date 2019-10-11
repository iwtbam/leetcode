#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> left_cans(size, 1);
        vector<int> right_cans(size, 1);

        for(int i = 1; i < size; i++)
        {
            if(ratings[i] > ratings[i-1])
                left_cans[i] = left_cans[i - 1] + 1;
        }

        for(int i = size - 2; i >= 0; i++)
        {
            if(ratings[i] > ratings[i+1])
                right_cans[i] = right_cans[i+1] + 1;
        }

        int sum = 0;

        for(int i = 0; i < size; i++)
            sum += max(left_cans[i], right_cans[i]);
            
        return sum;        
    }
};