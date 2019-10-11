class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}

class Solution {
    public int findTilt(TreeNode root) {
        helper(root);
        return till;
    }
    
    public int helper(TreeNode root){
        if(root == null)
            return 0;
        
        int lv = helper(root.left);
        int rv = helper(root.right);
        till += Math.abs(lv - rv);
        return root.val + lv + rv;
    }
    
    private int till = 0;
}