import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}

class Solution {
    public boolean isCompleteTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        boolean flag = false;
        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode node = q.poll();
                
                if(node.left != null)
                    q.offer(node.left);
                
                if(node.right !=null)
                    q.offer(node.right);
                
                if(flag){
                    if(node.left!=null || node.right!=null)
                        return false;
                }else{
                    if(node.left != null && node.right!=null)
                        continue;
                    
                    if(node.left==null && node.right!=null)
                        return false;
                    
                    flag = true;
                }
                
            }
        }
        
        return true;
    }
}