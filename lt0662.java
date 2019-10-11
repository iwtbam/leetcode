import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){
        val = x;
    }
}

class Solution {
    
    class NodePos {
        
        TreeNode node;
        int pos;
        NodePos(TreeNode node, int x){
            this.pos = x;
            this.node = node;
        }
    }
    
    public int widthOfBinaryTree(TreeNode root) {
        Queue<NodePos> q = new LinkedList<>();
        q.add(new NodePos(root, 0));
        int maxWidth = 0;
        while(!q.isEmpty()){
            int size = q.size();
            int start = -1, end = -1;
            for(int i = 0; i < size; i++){
                NodePos cur = q.poll();
                
                int pos = cur.pos;
                TreeNode node = cur.node;
                
                if(i == 0)
                    start = pos;
                
                if(i == size - 1)
                    end = pos;
                
                if(node.left != null){
                    q.add(new NodePos(node.left, 2 * pos));
                }
                
                if(node.right != null){
                    q.add(new NodePos(node.right, 2 * pos + 1));
                }
            }
            
            // System.out.println(start + " " + end);
            
            maxWidth = Math.max(maxWidth, end - start + 1);
        }
        return maxWidth;
    }
}