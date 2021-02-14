# https://leetcode-cn.com/problems/subarrays-with-k-different-integers/ 
# subarrays with k different integers 
class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
        return self.withMost(A, K) - self.withMost(A, K - 1)

    def withMost(self, A : List[int], K : int) -> int :
        size = len(A)
        l = 0
        r = 0
        count = 0
        res = 0
        record = [0 for _ in range(size + 1)]

        while r < size:
            if record[A[r]] == 0:
                count += 1

            record[A[r]] += 1

            while count > K:
                record[A[l]] -= 1
                if record[A[l]] == 0:
                    count -= 1
                l += 1
        
            res += r - l + 1
            r += 1

        return res