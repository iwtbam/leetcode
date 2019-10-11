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
    public int maxDepth(Node root) {
        if(root == null)
            return 0;
        int maxD = 0;
        for(Node node:root.children){
            maxD = Math.max(maxD, maxDepth(node));
        }
        return maxD + 1;
        
    }
}