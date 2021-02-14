// https://leetcode-cn.com/problems/minimum-number-of-removals-to-make-mountain-array/
// minimum number of removals to make mountain array
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        size_t size = nums.size();
        queue<int> q;
        vector<int> left(size, 0), right(size, 0);
        
        for(int i = 0; i < size; i++)
        {
            left[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] <= nums[j])
                    continue;
                left[i] = max(left[i], left[j] + 1); 
            }
        }
        
    
    
        int ans = 0;
        for(int i = size - 1; i >= 0; i--){
            right[i] = 1;
            for(int j = size - 1; j > i; j--){
                if(nums[i] <= nums[j])
                    continue;
                right[i] = max(right[i], right[j] + 1);
            }
            if(left[i] > 1 && right[i] > 1)
                ans = max(ans, left[i] + right[i] - 1);
        }
        
        // for(int i = 0; i < size; i++)
        //     cout << "(" << left[i] << "," << right[i] << ")" << endl;
        
        return size - ans;
    }
};