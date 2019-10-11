class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}

class Solution {
    public int longestConsecutive(TreeNode root) {
       
        if(root == null)
            return 0;
        
        int rootLen = 0;
        
        int inc = helper(root, 1);
        int dec = helper(root, -1);
        
        rootLen += inc + dec + 1;
        
        int left = longestConsecutive(root.left);
        int right = longestConsecutive(root.right);
        
        
        return Math.max(rootLen, Math.max(left, right));
    }
    
    public int helper(TreeNode node, int interval){
        if(node == null)
            return 0;
        
        int left = 0, right = 0;
        
        
        if(node.left !=null && node.left.val  == (node.val + interval)){
            left = helper(node.left, interval) + 1;
        }
        
        if(node.right!=null && node.right.val == (node.val + interval)){
            right = helper(node.right, interval) + 1;
        }
        
        return Math.max(left, right);
    }
}