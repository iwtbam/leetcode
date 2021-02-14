# https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/ 
# hua dong chuang kou de zui da zhi lcof 
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = collections.deque()

        res = []
        for i in range(len(nums)):
            while len(q) != 0 and nums[i] > nums[q[-1]]:
                q.pop()

            q.append(i)

            if i >= k - 1:
                res.append(nums[q[0]])
            if i - q[0] + 1 >= k:
                q.popleft()
            
        return res