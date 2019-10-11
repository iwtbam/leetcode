class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public int sumRootToLeaf(TreeNode root) {
        sumRootToLeaf(root, 0);
        return res; 
    }
    
    public void sumRootToLeaf(TreeNode root, int val){
        if(root == null){
            return;
        }
        
        int nVal = (val * 2 + root.val) % mod;
        
        if(root.left == null && root.right ==null){
            res = (res + nVal) % mod;
        }
        
        sumRootToLeaf(root.left,  nVal);
        sumRootToLeaf(root.right, nVal);
    }
    
    private int res = 0;
    private final int mod = (int)Math.pow(10, 9) + 7;
}