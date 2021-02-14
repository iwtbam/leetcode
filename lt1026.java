// https://leetcode-cn.com/problems/maximum-difference-between-node-and-ancestor/
// maximum difference between node and ancestor
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
    public int maxAncestorDiff(TreeNode root) {
        minAndMaxNodeVal(root);
        return maxVal;
    }
    
    public int[] minAndMaxNodeVal(TreeNode root){
        if(root == null)
            return new int[]{Integer.MIN_VALUE, Integer.MAX_VALUE};
        
        
        int[] lefts = minAndMaxNodeVal(root.left);
        int[] rights = minAndMaxNodeVal(root.right);
        
        int[] res = new int[2];
        res[0] = Math.max(lefts[0], rights[0]);
        res[1] = Math.min(lefts[1], rights[1]);
        
        if(root.left == null && root.right == null){
            return new int[]{root.val, root.val};
        }
        else
            maxVal = Math.max(maxVal, Math.max(Math.abs(root.val - res[0]), Math.abs(root.val - res[1])));
        
        res[0] = Math.max(root.val, res[0]);
        res[1] = Math.min(root.val, res[1]);
        
        return res;
    }
    
    
    private int maxVal = Integer.MIN_VALUE;
}