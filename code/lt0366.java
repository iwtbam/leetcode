import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public List<List<Integer>> findLeaves(TreeNode root) {
        
        
        List<List<Integer>> res = new ArrayList<>();
        
        if(root == null)
            return res;
        
        while(root.left != null || root.right != null){
            List<Integer> leaves = new ArrayList<>();
            helper(root, null, leaves);
            res.add(leaves);
        }
        
        List<Integer> leaves = new ArrayList<>();
        leaves.add(root.val);
        
        res.add(leaves);
        
        return res;
    }
    
    public void helper(TreeNode root, TreeNode pre, List<Integer> res){
        if(root == null)
            return;
        
        if(root.left == null && root.right == null){
            res.add(root.val);
            if(pre != null){
                if(pre.left == root)
                    pre.left = null;
                else
                    pre.right = null;
            }
            
            return;
        }
        
        helper(root.left,  root, res);
        helper(root.right, root, res);
        
    }
}