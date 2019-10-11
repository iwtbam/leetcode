class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
       
        if(root == null)
            return new TreeNode(val);
        
        TreeNode node = root, parent = null;
        while(node != null){
            parent = node;
            if(val < node.val){
                node = node.left;
            }else if(val > node.val){
                node = node.right;
            }else{
                return root;
            }
        }
        
        node = new TreeNode(val);
        if(node.val < parent.val)
            parent.left = node;
        else
            parent.right = node;
        
        
        return root;
    }
}