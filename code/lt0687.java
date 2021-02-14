class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public int longestUnivaluePath(TreeNode root) {
        return helper(root);
    }

    public int helper(TreeNode root, int index){
        if(root == null)
            return 0;

        int li = 0;
        int ri = 0;

        if(root.left != null && root.left.val == root.val){
            li = helper(root.left, index + 1);
        }
           

        if(root.right != null && root.right.val == root.val){
            ri = helper(root.right, index + 1);
        }
        
        return  Math.max(index, Math.max(li, ri));

    }

    public int helper(TreeNode node){
        if(node == null)
            return 0;
        
        int h = 0;
        if(node.left!=null && node.left.val == node.val){
            h = helper(node.left, 1);
        }
        
        if(node.right!=null && node.right.val == node.val){
            h += helper(node.right, 1);
        }
        
        return Math.max(h, Math.max(helper(node.left), helper(node.right)));
    }
}