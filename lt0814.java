// https://leetcode-cn.com/problems/binary-tree-pruning/
// binary tree pruning
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode pruneTree(TreeNode root) {
        
        if(root == null)
            return null;
        
        if(root.left != null)
            root.left = pruneTree(root.left);
        
        if(root.right != null)
            root.right = pruneTree(root.right);
        
        if(root.left == null && root.right == null && root.val == 0)
            root = null;
        
        
        return root;
    }
    
}