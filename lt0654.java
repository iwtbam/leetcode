class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){
        val = x;
    }
}

class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        if(nums.length == 0)
            return null;
        return helper(nums, 0, nums.length);
    }
    
    public TreeNode helper(int[] nums, int start, int end){
        if(end == start)
            return null;
        
        int pos = start;   
        
        for(int i = start; i < end; i++){
            if(nums[pos] < nums[i]){
                pos = i;
            }
        }
        
        TreeNode root = new TreeNode(nums[pos]);
        root.left = helper(nums, start, pos);
        root.right = helper(nums, pos + 1, end);
        return root;
    }
}