# https://leetcode-cn.com/problems/binary-tree-inorder-traversal/ 
# binary tree inorder traversal 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stack = []
        res   = []
        cur   = root
        while len(stack) or cur != None:
            while cur != None:
                stack.append(cur)
                cur = cur.left
            
            cur = stack.pop()
            res.append(cur.val)
            cur = cur.right
        
        return res