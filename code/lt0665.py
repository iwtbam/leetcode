# https://leetcode-cn.com/problems/non-decreasing-array/ 
# non decreasing array 
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:

        n = len(nums)

        if n == 1:
            return True

        incorrect = 0

        if nums[0] > nums[1]:
            nums[0] = nums[1]
            incorrect += 1
        
        for i in range(1, n - 1):

            r = nums[i + 1]
            if nums[i] > r:
                incorrect += 1
                if incorrect > 1:
                    return False
                l = nums[i - 1]

                if l <= r:
                    nums[i] = l
                else:
                    nums[i + 1] = nums[i]
                
        return True
                