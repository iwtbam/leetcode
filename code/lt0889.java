class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}

class Solution {
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        return constructFromPrePost(pre, 0, pre.length, post, 0, post.length);
    }
    
    
    public TreeNode constructFromPrePost(int[] pre, int s1, int e1,  int[] post, int s2, int e2){
        
        if(e1 - s1 <= 0)
            return null;
        
        
        if(pre[s1] != post[e2 - 1])
            return null;
        
        TreeNode node = new TreeNode(pre[s1]);
   
        if(e1 - s1 == 1)
            return node;
                
        int i = s2;
        int j = s1 + 1;
        for(; i < e2; i++, j++){
            if(pre[s1 + 1] == post[i])
                break;
        }
        
        
        node.left = constructFromPrePost(pre, s1 + 1, j + 1, post,  s2,  i + 1);
        node.right = constructFromPrePost(pre, j + 1,  e1,  post, i + 1,  e2 - 1);
        
        return node;
    }

}