# https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/ 
# shu zu zhong shu zi chu xian de ci shu lcof 
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        res = 0
        for num in nums:
            res ^= num

        # ÕÒÄÄÒ»Î»1
        bit = 1
        while bit &  res == 0:
            bit = bit << 1

        a, b = 0, 0

        for num in nums:
            if bit & num == 0:
                a ^= num
            else:
                b ^= num

        return [a, b]

        
        