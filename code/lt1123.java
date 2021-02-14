import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}

class Solution {
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        if(root == null)
            return null;
        
        int lh = height(root.left);
        int rh = height(root.right);
        
        if(lh == rh)
            return root;
        
        return lh > rh ? lcaDeepestLeaves(root.left) : lcaDeepestLeaves(root.right);
    }
    
    public int height(TreeNode root){
        if(root == null)
            return 0;
        
        return Math.max(height(root.left), height(root.right)) + 1; 
    }
}

// 这法子有点蠢, 题刷不少, 长进不多
// class Solution {
//     public TreeNode lcaDeepestLeaves(TreeNode root) {
        
//         Set<TreeNode> res = new HashSet<>();
//         preorder(root, null, 0);
        
        
//         for(TreeNode node: leafs){
//             res.add(node);
//         }
        
        
        
//         while(res.size() > 1){
//             Set<TreeNode> nSet = new HashSet<>();
//             for(TreeNode node: res){
//                 nSet.add(parents.get(node));
//             }
            
//             res = nSet;
//         }
        
//         for(TreeNode node: res)
//             return node;
        
//         return null;
        
//     }
    
    
//     public void preorder(TreeNode cur, TreeNode pre, int deep){
//         if(cur == null)
//             return;
//         parents.put(cur, pre);
//         if(deep < minDeep){
//             minDeep = deep;
//             leafs.clear();
//         }
        
//         if(deep == minDeep)
//             leafs.add(cur);
        
//         preorder(cur.left, cur, deep - 1);
//         preorder(cur.right, cur, deep - 1);
//     }
    
//     private Map<TreeNode, TreeNode> parents = new HashMap<>();
//     private ArrayList<TreeNode> leafs = new ArrayList<>();
//     private int minDeep = 0;
// }