import java.util.*;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class FindElements {

    public FindElements(TreeNode root) {
        this.root = root;
        init(root, 0);
    }
    
    
    private void init(TreeNode node, int val){
        if(node == null)
            return;
        
        node.val = val;
        nums.add(val);
        init(node.left,  val * 2 + 1);
        init(node.right, val * 2 + 2);
    }
    
    public boolean find(int target) {
        return nums.contains(target);
    }
    
    private TreeNode root = null;
    private Set<Integer> nums = new HashSet<>();
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */