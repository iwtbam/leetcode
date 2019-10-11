class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public TreeNode increasingBST(TreeNode root) {            
        TreeNode top = new TreeNode(0);
        pre = top;
        inorder(root);
        return top.right;
    }
    
    public void inorder(TreeNode root){
        if(root == null)
            return;
        
        inorder(root.left);
        root.left = null;
        pre.right = root;
        pre = root;
        inorder(root.right);
    }
    
    private TreeNode pre = null;
    
}