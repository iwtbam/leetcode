import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){val = x;}
}

class Solution {
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        if(root == null)
            return null;

        TreeNode pre = new TreeNode(0);
        pre.left = root;
        helper(pre, 0, limit);
        return pre.left;
    }

    public boolean helper(TreeNode node, int pre, int limit){
        if(node == null)
            return true;

        if(node.left == null && node.right == null)
            return pre + node.val < limit;

        boolean leftDeleted = helper(node.left,  pre + node.val, limit);
        boolean rightDeleted= helper(node.right, pre + node.val, limit);
        if(leftDeleted)
            node.left = null;
        if(rightDeleted)
            node.right = null;
        return leftDeleted && rightDeleted;
    }   
}

// 2019-11-15:10-54 不优
// class Solution {
//     public TreeNode sufficientSubset(TreeNode root, int limit) {
//         if(root == null)
//             return null;
//         TreeNode pre = new TreeNode(0);
//         pre.left = root;
//         Map<TreeNode, Integer> prefixs = new HashMap<>();
//         prefix(root, 0  , prefixs);
//         helper(root, pre, prefixs, limit);
//         return pre.left;
//     }

//     public void prefix(TreeNode node, int pre, Map<TreeNode, Integer> prefixs){
//         if(node == null)
//             return;

//         prefixs.put(node, pre);
//         prefix(node.left,  pre + node.val, prefixs);
//         prefix(node.right, pre + node.val, prefixs);
//     }

//     public Integer helper(TreeNode node, TreeNode pre,  Map<TreeNode, Integer> prefixs, int limit){
//         if(node == null)
//             return null;
        
//         Integer left  = helper(node.left , node, prefixs, limit);
//         Integer right = helper(node.right, node, prefixs, limit);

//         int maxVal = left == null ? (right == null ? 0 : right) : (right == null ? left : Math.max(left, right));
        
//         int curVal = prefixs.get(node) + node.val + maxVal; 
//         if(curVal < limit){
//             if(pre.left == node)
//                 pre.left = null;
//             else
//                 pre.right = null;
//         }

//         return node.val + maxVal;
//     }

//     private final int UN_SOLVED = Integer.MIN_VALUE;
// }