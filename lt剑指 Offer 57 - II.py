# https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/ 
# he wei sde lian xu zheng shu xu lie lcof 
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        l, r = 1, 2
        datas = list(range(0, target))
        res = []
        while r < target:
            s = (l + r) * (r - l + 1) / 2
            if s <= target:
                if s == target:
                    res.append(datas[l:r + 1])
                r += 1
            else:
                l += 1
        return res


