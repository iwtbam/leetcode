# https://leetcode-cn.com/problems/find-majority-element-lcci/ 
# find majority element lcci 
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        num, total, vote = nums[0], 1, 1
        size = len(nums)
        for i in range(1, size):
            total += 1
            if num == nums[i]:
                vote += 1
            else:
                if vote * 2 < total:
                    num = nums[i]
                    vote = 1
                    total = 1
        
        vote = sum([val == num for val in nums])
        return num if vote * 2 > len(nums) else -1

