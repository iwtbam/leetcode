import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public boolean checkEqualTree(TreeNode root) {
        int total = sum(root);
        
        System.out.println(total);
        if(Math.abs(total) % 2 == 1)
            return false;
        
        if(total == 0  && memos.get(0) == 1)
            return false;
            
        
        return memos.containsKey(total / 2);
    }
    
    public int sum(TreeNode root){
        if(root == null)
            return 0;
        
        if(root.left == null && root.right == null){
            memos.put(root.val, memos.getOrDefault(root.val, 0) + 1);
            return root.val;
        }
        
        int res =  root.val + sum(root.left) + sum(root.right);
        memos.put(res, memos.getOrDefault(res, 0) + 1);
        return res;
    }
    
    private Map<Integer, Integer> memos = new HashMap<>();
}