
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {      
        size_t size = nums.size();
        if(size == 0)
            return {};
        
        vector<int> left =  {nums.begin(), nums.end()};
        vector<int> right = {nums.begin(), nums.end()};
        vector<int> res = {};
        int seg = size / k;
        
        for(int i = 0; i < seg; i++)
        {
            for(int j = 1; j < k; j++)
                left[i*k+j] = max(left[i*k+j], left[i*k+j-1]);
            
            for(int j = k - 2; j >= 1; j--)
                right[i*k+j] = max(right[i*k+j], right[i*k+j+1]);
        }

        int rest = size % k;

        for(int i = k * seg + 1; i < k*seg + rest; i++)
            left[i] = max(left[i], left[i-1]);

        for(int i = size - 2; i >= k * seg; i--)
            right[i] = max(right[i], right[i+1]);

        
        for(int i = 0; i < size - k + 1; i++)
            res.push_back(max(right[i], left[i+k-1]));
        
        return res;
        
    }
};