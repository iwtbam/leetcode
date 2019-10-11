class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}

class Solution {
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        if(root == null)
            return null;
        
        int lh = height(root.left);
        int rh = height(root.right);
        
        if(lh == rh)
            return root;
        return lh > rh ? subtreeWithAllDeepest(root.left) : subtreeWithAllDeepest(root.right);
    }
    
    public int height(TreeNode node){
        if(node == null)
            return 0;
        return Math.max(height(node.left), height(node.right)) + 1;
    }
}