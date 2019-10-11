import java.util.*;

class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        
      
        
        Queue<Node> q = new LinkedList<>();
        List<List<Integer>> res = new ArrayList<>();
        if(root == null)
            return res;
        
        q.offer(root);
        
        while(!q.isEmpty())
        {
            int size = q.size();
            List<Integer> temp = new ArrayList<>();
            for(int i = 0; i < size; i++){
                Node cur = q.poll();
                temp.add(cur.val);
                for(Node node:cur.children){
                    q.offer(node);
                }
            }
            res.add(temp);
        }
        return res;
    }
}