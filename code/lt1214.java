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
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        if(root1 == null)
            return false;
        
        if(find(root2, target - root1.val))
            return true;
        
        if(twoSumBSTs(root1.left, root2, target))
            return true;
        
        if(twoSumBSTs(root1.right, root2, target))
            return true;
        
        return false; 
    }
    
    public boolean find(TreeNode node, int target){
        while(node !=null){
            if(target == node.val)
                return true;
            if(target > node.val){
                node = node.right;
            }else{
                node = node.left;
            }
        }
        
        return false;
    }
}