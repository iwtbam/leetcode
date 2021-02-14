import java.util.LinkedList;
import java.util.Queue;

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x};
}

class Solution {
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        Queue<TreeNode> q = new LinkedList<>();
        int curDeep = 1;

        if(curDeep + 1 > d){
            TreeNode vNode = new TreeNode(v);
            vNode.left = root;
            return vNode;
        }

        q.add(root);
        while(!q.isEmpty() && curDeep + 1 != d){
            int size = q.size();
            System.out.println(size);
            for(int i = 0; i < size; i++){
                TreeNode node = q.poll();
                if(node.left!=null){
                    q.add(node.left);
                }

                if(node.right!=null){
                    q.add(node.right);
                }
            }

            curDeep++;
        }

        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode node = q.poll();
            if(node.left!=null){
                TreeNode temp = node.left;
                TreeNode vNode = new TreeNode(v);
                node.left = vNode;
                vNode.left = temp;
            }else{
                node.left = new TreeNode(v);
            }
                
            if(node.right!=null){
                TreeNode temp = node.right;
                TreeNode vNode = new TreeNode(v);
                node.right = vNode;
                vNode.right = temp;
            }else{
                node.right = new TreeNode(v);
            }
        }
        
        return root;      
    }
}