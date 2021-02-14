class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){val = x;}
}

class Solution {
    public double maximumAverageSubtree(TreeNode root) {
        helper(root);
        return maxAvg;
    }
    
    public double[] helper(TreeNode node){
        if(node == null)
            return new double[]{0, 0};
        double[] left = helper(node.left);
        double[] right = helper(node.right);
        int count = (int)(left[0] + right[0] + 1);
        double avg = (left[0] * left[1] + right[0] * right[1]  + node.val) / count;
        maxAvg = Math.max(avg, maxAvg);
        return new double[]{count, avg};
    }
    
    private double maxAvg = 0.0;
}