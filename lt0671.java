class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public int findSecondMinimumValue(TreeNode root) {
        if(root == null || root.left == null)
            return -1;
        
        TreeNode pre = new TreeNode(Integer.MAX_VALUE);
        
        return findVal(root, pre);
    }
    
    public int findVal(TreeNode root, TreeNode parent){
    
        if(root == null)
            return -1;
        
        if(root.val > parent.val)
            return root.val;
        
        int lv = findVal(root.left,  root);
        int rv = findVal(root.right,  root);
        
        if(lv == -1)
            return rv;
        
        if(rv == -1)
            return lv;
        
        return Math.min(lv, rv);
        
    }
}