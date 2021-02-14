# https://leetcode-cn.com/problems/maximum-subarray/ 
# maximum subarray 
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = min(nums)
        sum_val = 0
        for num in nums:
            sum_val += num
            if sum_val > res:
                res = sum_val
            
            if sum_val < 0:
                sum_val = 0
        
        return res