// https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// longest continuous subarray with absolute diff less than or equal to limit
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> record;
        size_t size = nums.size();
        int left = 0, right = 0, max_len = 0;
        while(right < size){
            record.insert(nums[right]);
            while(*record.rbegin() - *record.begin() > limit && left <= right){
                record.erase(record.find(nums[left++]));
            }

            max_len = max(max_len, right - left + 1);
            right++;
        }

        return max_len;
    }
};