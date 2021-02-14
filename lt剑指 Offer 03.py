# https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/ 
# shu zu zhong zhong fu de shu zi lcof 
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:

        """
            list : a = [] , a =  list() , a = [1, 2, 3]
            tuple : a = (), a = tuple(), a = (1, 2, 3) 
            dict: a = {}, a = dict()
            set : a = set()
        """



        record=set()
        for i in range(len(nums)):
            if nums[i] in record:
                return nums[i]
            else:
                record.add(nums[i]) 
