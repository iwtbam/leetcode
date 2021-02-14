class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public int minDiffInBST(TreeNode root) {
        inorder(root);
        return min;
    }
    
    
    public void inorder(TreeNode node){
        if(node == null)
            return;
        
        inorder(node.left);
        if(pre!=null)
            min = Math.min(min, node.val - pre.val);
        pre = node;
        
        inorder(node.right);
    }
    
    private int min = Integer.MAX_VALUE;
    private TreeNode pre = null;
}