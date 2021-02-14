import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> r1 = new ArrayList<Integer>();
        List<Integer> r2 = new ArrayList<Integer>();
        
        helper(root1, r1);
        helper(root2, r2);
        
        if(r1.size() != r2.size())
            return false;
        
        int size = r1.size();
        
        for(int i = 0; i < size; i++)
            if(r1.get(i) != r2.get(i))
                return false;
        
        return true;
    }
    
    public void helper(TreeNode node, List<Integer> res){
        if(node == null)
            return;
        if(node.left == null && node.right == null)
            res.add(node.val);
        helper(node.left, res);
        helper(node.right,res);
    }
}