#include <vector>
#include <algorithm>

using  namespace std;


#define S1


#if defined S1
// 贪心
class Solution{
public:
    int jump(vector<int>& nums){
        int end = 0;
        int max_pos = 0;
        int step = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            max_pos = max(max_pos, nums[i] + i);
            if(i == end){
                end = max_pos;
                step++;
            }            
        }
        return step;
    }
};

#elif defined S2
//dp 超时

class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.empty())
            return 0;
        
        int size = nums.size();
        vector<int> dp(size, INT_MAX - 1);
        
        dp[0] = 0;
        for(int i = 0; i < size; i++)
        {
            for(int j = 1; j <=nums[i] && i + j < size;j++)
                dp[i + j] = min(dp[i+j],dp[i] + 1);
        }
      
        
        return dp[size - 1];
    }
};

#endif