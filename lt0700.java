class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}

class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        TreeNode node = root;
        
        while(node != null){
            if(val < node.val){
                node = node.left;
            }else if(val > node.val){
                node = node.right;
            }else{
                return node;
            }
        }
        
        return node;
    }
}