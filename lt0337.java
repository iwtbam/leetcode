import java.util.HashMap;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){
        val = x;
    }
};

class Solution {
    public int rob(TreeNode root) {
        if(root == null)
        return 0;

        if(record.get(root)!=null)
            return record.get(root);
        
        Integer noRobVal = rob(root.left) + rob(root.right);
        Integer RobVal = root.val;
        if(root.left !=null)
            RobVal = RobVal + rob(root.left.left) + rob(root.left.right);
        
        if(root.right !=null)
            RobVal = RobVal + rob(root.right.left) + rob(root.right.right);

        record.put(root, Math.max(noRobVal, RobVal));
        return record.get(root);
    }

    private HashMap<TreeNode, Integer> record = new HashMap<>();
}