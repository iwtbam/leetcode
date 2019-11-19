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
    public int largestBSTSubtree(TreeNode root) {
        helper(root);
        return maxNode;    
    }
    
    public int[] helper(TreeNode node){
        if(node == null){
            return new int[]{0, Integer.MAX_VALUE, Integer.MIN_VALUE};
        }
        
        int[] left = helper(node.left);
        int[] right = helper(node.right);
        
        int maxV = left[2];
        int minV = right[1];
        
        if(left[0] == -1 || right[0] == -1)
            return new int[]{-1, -1, -1};
            
        boolean isBST = true;
        
        if(node.left!=null){
            isBST = node.val > maxV;
        }
            
        if(isBST && node.right != null){
            isBST = node.val < minV;
        }
        
        maxV = Math.max(right[2], node.val);
        minV = Math.min(left[1], node.val);
                
        int res = isBST ? left[0] + right[0] + 1 : -1;
        maxNode = Math.max(res, maxNode);
        return new int[]{res, minV, maxV};
        
    }
     
    private int maxNode = 0;
}