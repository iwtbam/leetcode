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
    public List<Integer> postorder(Node root) {
        
        
        Stack<Node> s = new Stack<>();
        List<Integer> res = new ArrayList<>();
        
        
        if(root == null)
            return res;
        
        Set<Node> record = new HashSet<>();
        s.push(root);
        while(!s.isEmpty()){
            Node top = s.peek();
            //record.add(top);
            // System.out.println(top.val);
            if(top.children.isEmpty()){
                record.add(top);
                res.add(s.pop().val);
            }else{
                if(record.contains(top)){
                    res.add(s.pop().val);
                    continue;
                }
                
                record.add(top);
            
                for(int i = top.children.size() - 1; i >=0; i--){
                    s.push(top.children.get(i));
                }
            }
        }
        
        return res;
    }