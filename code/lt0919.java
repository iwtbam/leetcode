import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){val = x;}
}

class CBTInserter {

    public CBTInserter(TreeNode root) {
        this.root = root;
        if(root!=null)
            initQ(root);
    }    
    
    public void initQ(TreeNode  root){
        Queue<TreeNode> lq = new LinkedList<>();
        lq.offer(root);
        while(!lq.isEmpty())
        {
            int size = lq.size();
            for(int i = 0; i < size; i++){
                TreeNode node = lq.poll();
                if(node.left !=null)
                    lq.offer(node.left);
                if(node.right != null)
                    lq.offer(node.right);
                
                
                if(node.left==null ||  node.right == null)
                    q.offer(node);
            }
        }
    }
    
    public int insert(int v) {
        if(root == null){
            root = new TreeNode(v);
            q.offer(root);
            return v;
        }
        
        TreeNode node = q.peek();
        TreeNode newNode = new TreeNode(v);
        if(node.left == null)
            node.left = newNode;
        else{
            node.right = newNode;
            q.poll();
        }
        
      
        q.offer(newNode);
        return node.val;
    }
    
    public TreeNode get_root() {
        return root;
    }
    
    private TreeNode root = null;
    private Queue<TreeNode> q = new LinkedList<>();
}