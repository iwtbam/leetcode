class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}

class Solution {
    public String smallestFromLeaf(TreeNode root) {
        smallestFromLeaf(root, new StringBuffer());
        return smallestString;
    }
    
    public void smallestFromLeaf(TreeNode node, StringBuffer sb){
        
        if(node == null)
            return ;
        
        sb.append((char)(node.val + 'a'));
        if(node.left == null && node.right == null){
            //System.out.println(sb);
            sb.reverse();
            String nStr = sb.toString();
            sb.reverse();
            if(smallestString == null){
                smallestString = nStr;
            }else{
                if(smallestString.compareTo(nStr) > 0)
                    smallestString = nStr;
            }
           
        }
        
        smallestFromLeaf(node.left, sb);
        smallestFromLeaf(node.right,sb);
        sb.deleteCharAt(sb.length() - 1);
    }
    
    private String smallestString = null;
}