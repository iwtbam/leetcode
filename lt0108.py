# https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/ 
# convert sorted array to binary search tree 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if len(nums) == 0:
            return None
        
        privot = len(nums) // 2

        root = TreeNode(nums[privot])

        root.left = self.sortedArrayToBST(nums[:privot])
        root.right = self.sortedArrayToBST(nums[privot + 1:])

        return root;