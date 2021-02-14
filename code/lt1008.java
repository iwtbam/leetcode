class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){val = x;}
}


class Solution {
    public TreeNode bstFromPreorder(int[] preorder) {
        return bstFromPreorder(preorder, 0, preorder.length);
    }
    
    public TreeNode bstFromPreorder(int[] preorder, int s, int e){
        if(e <= s)
            return null;
        
        TreeNode node = new TreeNode(preorder[s]);
        
        if(e == s + 1)
            return node;
        
        int i = s + 1;
        for(; i < e; i++){
            if(preorder[i] > preorder[s])
                break;
        }
        
        node.left = bstFromPreorder(preorder, s + 1, i);
        node.right = bstFromPreorder(preorder, i, e);
        
        return node;
    }
}