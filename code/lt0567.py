# https://leetcode-cn.com/problems/permutation-in-string/ 
# permutation in string 
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:

        len1, len2 = len(s1), len(s2)

        if len2 < len1:
            return False

        count1 = [0 for _ in range(26)]
        count2 = [0 for _ in range(26)]

        r = 0

        while r < len1:
            count1[ord(s1[r]) - 97] += 1
            count2[ord(s2[r]) - 97] += 1
            r += 1
        
        if count1 == count2:
            return True

        while r < len2:

            count2[ord(s2[r]) - 97] += 1
            count2[ord(s2[r - len1]) - 97] -= 1

            if count1 == count2:
                return True
            r += 1
        return False