# https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/ 
# cong wei dao tou da yin lian biao lcof 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        lis=[]

        cur = head
        pre =None

        while cur!=None:
            post=cur.next
            cur.next = pre
            pre=cur
            cur=post
        
        while pre!=None:
            lis.append(pre.val)
            pre=pre.next
        return lis






