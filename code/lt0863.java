import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;
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
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        toGraph(root, null);
        Queue<TreeNode> q = new LinkedList<>();
        HashMap<TreeNode, Boolean> record = new HashMap<>();
        q.add(target);
        record.put(target, true);

        int cur = 0;
        while(!q.isEmpty() && cur < K){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode node = q.poll();
                
                if(node.left!=null && record.get(node.left) == null){
                    q.add(node.left);
                    record.put(node.left, true);
                }
                
                if(node.right!=null && record.get(node.right) == null){
                    q.add(node.right);
                    record.put(node.right, true);
                }
                
                if(parents.get(node)!=null && record.get(parents.get(node)) == null){
                    q.add(parents.get(node));
                    record.put(parents.get(node), true);
                }
            }
            
            cur++;
        }
        
        List<Integer> res = new ArrayList<>();
        for(TreeNode node: q){
            res.add(node.val);
        }
        
        return res;
    }
    
    
    public void toGraph(TreeNode root, TreeNode pre){
        if(root != null){
            parents.put(root, pre);
            toGraph(root.left, root);
            toGraph(root.right, root);
        }
    }
    
    private Map<TreeNode, TreeNode> parents = new HashMap<>();
}