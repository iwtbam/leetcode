class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public int minCameraCover(TreeNode root) {
        if(root == null)
            return 0;
        
        if(helper(root)==2)
            ans++;
        return ans;
    }
    
    public int helper(TreeNode node){
        if(node == null)
            return 1;
        
        int left = helper(node.left);
        int right = helper(node.right);
        
        if(left == 2 || right == 2){
            ans++;
            return 0;
        }else if(left == 0 || right == 0){
            return 1;
        }else{
            return 2;
        }
        
    }
    
    private int ans = 0;
}