#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0, size = nums.size();
        int min_len = INT_MAX, cur_len = 0, cur_sum = 0;
        
        while(right < size)
        {
            cur_sum += nums[right];
            cur_len++;
            
            while(cur_sum >= s)
            {
                min_len = min(min_len, cur_len);
                cur_sum -= nums[left++];
                cur_len--;
            }

            right++;
        }

        return min_len == INT_MAX ? 0 : min_len; 
    }
};