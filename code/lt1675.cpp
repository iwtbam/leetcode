// https://leetcode-cn.com/problems/minimize-deviation-in-array/
// minimize deviation in array
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        size_t n = nums.size();
        int min_val = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1){
                nums[i] *= 2;
            }
            q.push(nums[i]);
            min_val = min(nums[i], min_val);
        }

        int res = q.top() - min_val;
        while(q.top() % 2 == 0){
            int max_val = q.top();
            q.pop();
            q.push(max_val / 2);
            min_val = min(min_val, max_val / 2);
            res = min(q.top() - min_val, res);
        }

        return res;
    }
};