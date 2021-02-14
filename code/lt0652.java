import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        List<TreeNode> res = new ArrayList<TreeNode>();
        Map<String, Integer> record = new HashMap<String, Integer>();
        helper(root, record, res);
        return res;
    }
    
    public String helper(TreeNode root, Map<String, Integer> record, List<TreeNode> res){
        
    
        if(root != null){
            String ls = helper(root.left, record, res);
            String rs = helper(root.right, record, res);
            String s = "(" + ls + ")" + root.val + "(" + rs + ")";
            if(record.get(s)!=null){
                if(record.get(s) == 1){
                    res.add(root);
                }
                record.put(s, 2);
            }
            else
                record.put(s, 1);

            return s; 
        }
        
        return new String();
    }
    
}