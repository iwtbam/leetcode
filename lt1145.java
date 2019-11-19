class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        TreeNode targetNode = findTargetNode(root, x);
        int num1 = nodeNum(targetNode);
        if(n - num1 > num1)
            return true;
        int num2 = nodeNum(targetNode.left);
        if(num2 > n - num2)
            return true;
        
        int num3 = nodeNum(targetNode.right);
        if(num3 > n - num3)
            return true;
        return false;
    }
    
    public TreeNode findTargetNode(TreeNode root, int targetVal){
        if(root == null)
            return null;
        
        if(root.val == targetVal)
            return root;
        
        TreeNode leftRes = findTargetNode(root.left, targetVal);
        
        if(leftRes!=null)
            return leftRes;
        
        
        return findTargetNode(root.right, targetVal);
    }
    
    public int nodeNum(TreeNode root){
        if(root == null)
            return 0;
        return nodeNum(root.left) + nodeNum(root.right) + 1;
    }
}