// https://leetcode-cn.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
// maximum number of non overlapping subarrays with sum equals target
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        vector<pair<int, int>> intervals;
        unordered_map<int, int> record;
        int size = nums.size();
        int sum = 0;
        record[0] = -1;
        for(int i = 0; i < size; i++){
            sum += nums[i];
            if(record.count(sum - target) == 1){
                intervals.emplace_back(record[sum - target] + 1, i);
            }
            record[sum] = i;
        }
        int end = -1, ans = 0;
        size = intervals.size();
        for(int i = 0; i < size; i++){
            if(intervals[i].first > end){
                end = intervals[i].second;
                ans++;
            }    
        }
        return ans;
    }
};