class TreeNode
{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){
        val = x;
    }
}

class Solution {
    public TreeNode convertBST(TreeNode root){
        helper(root);
        return root;
    }
    


    public void helper(TreeNode root){
        if(root != null){
            helper(root.right);
            sVal += root.val;
            root.val = sVal;
            helper(root.left);
        }
    }
    
    private int sVal = 0;
}
