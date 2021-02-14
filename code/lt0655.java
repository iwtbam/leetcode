import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    
    public List<List<String>> printTree(TreeNode root) {
        int h = height(root);
        int total = (int)Math.pow(2, h) - 1;
        List<List<String>> res = new ArrayList<>();
        
        for(int i = 0; i < h; i++){
            res.add(new ArrayList<String>(Collections.nCopies(total, new String())));
        }
        
     
        helper(root, 0, 0, total, res);
        return res;
    }
    
    
    
    public int height(TreeNode node){
        if(node == null)
            return 0;
        
        return Math.max(height(node.left), height(node.right)) + 1;
    }
    
    public void helper(TreeNode root, int y, int s, int e, List<List<String>> res){
        if(root == null)
            return;
        int mid = (s + e) >> 1;
        res.get(y).set(mid, root.val + "");
        helper(root.left, y + 1, s, mid, res);
        helper(root.right, y + 1, mid + 1, e, res);
    }
}