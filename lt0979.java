import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}

class Solution {
    public int distributeCoins(TreeNode root) {
        helper(root);
        return ans;
    }
    
    public int helper(TreeNode root){
        if(root == null)
            return 0;
        
        int L = helper(root.left);
        int R = helper(root.right);
        
        ans += Math.abs(L) + Math.abs(R);
        
        return root.val + L + R - 1;
        
    }
    
    
    private int ans = 0;
}