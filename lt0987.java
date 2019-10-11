import java.util.*;


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val=x; }
}

class Solution {
    
    class NodePos {
        int x;
        int y;
        int val;
        NodePos(int x, int y, int val){
            this.x = x;
            this.y = y;
            this.val = val;
        }
        NodePos(NodePos other){
            this.x = other.x;
            this.y = other.y;
            this.val = other.val;
        }
    }
    
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<NodePos> nodes = new ArrayList<>();
        inorder(root, nodes, 0, 0);
        Collections.sort(nodes, new Comparator<NodePos>(){
            public int compare(NodePos np1, NodePos np2){
                if(np1.x == np2.x && np1.y == np2.y)
                    return np1.val - np2.val;
                if(np1.x == np2.x)
                    return np2.y - np1.y;
                return np1.x - np2.x;
            }
        });
        
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> line = new ArrayList<>();
        
        int size = nodes.size();
        
        if(size == 0)
            return res;
        
        NodePos fakePos = new NodePos(nodes.get(size - 1));
        fakePos.x = fakePos.x + 1;
        nodes.add(fakePos);
        
        for(int i = 0; i < nodes.size() - 1; i++){
            line.add(nodes.get(i).val);
            if(nodes.get(i).x != nodes.get(i+1).x){
                res.add(new ArrayList<>(line));
                line.clear();
            }
        }
        
        
        if(line.size()!=0)
            res.add(line);
        
        return res;
    }
    
    public void inorder(TreeNode root, List<NodePos> nodes, int x, int y){
        if(root == null)
            return;
        
        nodes.add(new NodePos(x, y, root.val));
        inorder(root.left, nodes, x - 1, y - 1);
        inorder(root.right, nodes, x + 1, y - 1);
        
    }
}