# https://leetcode-cn.com/problems/smallest-string-with-a-given-numeric-value/ 
# smallest string with a given numeric value 
class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        
        z = (k - n) // 25
        m = 0 if (k - n) % 25 == 0 else 1
        
        res = ['a' for _ in range(n - z - m)]
        
        if m > 0:
            res.append(chr(97 + (k - n) % 25))
        
        res.extend(['z' for _ in range(z)])
        return ''.join(res)  
        