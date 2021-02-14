# https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/ 
# ti huan kong ge lcof 
class Solution:
    def replaceSpace(self, s: str) -> str:
        a = list(s)
        for i in range(len(a)):
            if a[i] == " ":
                a[i] = "%20"
           
        return ''.join(a)

