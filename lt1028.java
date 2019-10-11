import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){ val = x;}
}


class Solution {
    public TreeNode recoverFromPreorder(String S) {
        int e = S.length(), s = 0;
        HashMap<TreeNode, Integer> record = new HashMap<>();
        Stack<TreeNode> nodes = new Stack<>();
        TreeNode head = null;
        
        while(s < e){
            int s1 = s;
           
            while(S.charAt(s1) == '-')
                s1++;
            
        
            int s2 = s1;
            while(s2 < e && S.charAt(s2)!='-' )
                s2++;
            
          
            
            TreeNode node = new TreeNode(Integer.parseInt(S.substring(s1, s2)));
            int deep = s1 - s;
             s = s2;
  
            record.put(node, deep);
            if(!nodes.isEmpty()){
               
                
                while(nodes.size()!=0 && record.get(nodes.peek()) >= deep)
                    nodes.pop();
          
                TreeNode top = nodes.peek();
                
                System.out.println(top.val);
             
                
                if(top.left==null)
                    top.left = node;
                else
                    top.right = node;
                
            }else{
                head = node;
            }
            
            nodes.push(node);
        }
        
        
        return head;
    } 
}