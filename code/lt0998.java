class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){val = x;}
}


class Solution {
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        if(root == null)
            return new TreeNode(val);
        if(root.val < val){
            TreeNode bNode = new TreeNode(val);
            bNode.left = root;
            return bNode;
        }
        helper(root, null, val);
        return root;
    }
    
    public void helper(TreeNode root, TreeNode pre, int val){
        if(root == null){
            TreeNode bNode = new TreeNode(val);
            pre.right = bNode;
            return;
        }
        
        
        if(root.val < val){
            TreeNode bNode = new TreeNode(val);
            pre.right = bNode;
            bNode.left = root;
            return;
        }
        
        helper(root.right, root, val);
    }
}