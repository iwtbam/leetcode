import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}

class Solution {
    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        flip(root, voyage);
        if(!res.isEmpty() && res.get(0)==-1){
            res.clear();
            res.add(-1);
        }
        return res;
    }
    
    
    public void flip(TreeNode root, int[] voyage){
        if(root == null)
            return;
    
        if(root.val != voyage[index++]){
            res.clear();
            res.add(-1);
            return;
        }
        
        if(root.left!=null && index < voyage.length && root.left.val != voyage[index]){
            res.add(root.val);
            flip(root.right, voyage);
            flip(root.left, voyage);
        }else{
            flip(root.left, voyage);
            flip(root.right, voyage);
        }
        
        
    }
    
    private int index = 0;
    private List<Integer> res = new ArrayList<>();
}