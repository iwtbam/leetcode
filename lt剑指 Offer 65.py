# https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/ 
# bu yong jia jian cheng chu zuo jia fa lcof 
class Solution(object):
    def add(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        if a == 0:
            return b
        
        if b == 0:
            return a
        
        return add(a ^ b, (a & b) << 1)