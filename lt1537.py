# https://leetcode-cn.com/problems/get-the-maximum-score/ 
# get the maximum score 
class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        mod = 10**9+7
        l1 = len(nums1)
        l2 = len(nums2)
        i=0
        j=0
        p1, p2 = 0, 0
        res, res1, res2 = 0, 0, 0
        

        while p1 < l1 and p2 < l2:
            if nums1[p1] > nums2[p2]:
                res2 += nums2[p2]
                p2 += 1
            elif nums1[p1] < nums2[p2]:
                res1 += nums1[p1]
                p1 += 1
            elif nums1[p1]==nums2[p2]:
                res1 += nums1[p1]
                res2 += nums2[p2]
                res = max(res1,res2)
                res1 = res
                res2 = res
                p1 +=1
                p2 +=1
                
        if p1 == l1:
            res2 += sum(nums2[p2:])
        if p2 == l2:
            res1 += sum(nums1[p1:])
        
        return max(res1,res2) % mod